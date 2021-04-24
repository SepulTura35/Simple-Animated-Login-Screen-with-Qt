
// #include <QGraphicsEffect>
#include "customshadoweffect.h"
#include <QPainter>

CustomShadowEffect::CustomShadowEffect(QObject *parent) :
    QGraphicsEffect(parent),
    _distance(4.0f),
    _blurRadius(10.0f),
    _color(0, 0, 0, 80)
{
}

QT_BEGIN_NAMESPACE
  extern Q_WIDGETS_EXPORT void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0 );
QT_END_NAMESPACE

void CustomShadowEffect::draw(QPainter* painter)
{
    // eğer dış çizimde hata olursa sadece gölgeyi çizdir;
    if ((blurRadius() + distance()) <= 0) {
        drawSource(painter);
        return;
    }

    PixmapPadMode mode = QGraphicsEffect::PadToEffectiveBoundingRect;
    QPoint offset;
    const QPixmap px = sourcePixmap(Qt::DeviceCoordinates, &offset, mode);

    // return (eğer sorce = null ise)
    if (px.isNull())
        return;

    // dönüşümü kaydediyoruz
    QTransform restoreTransform = painter->worldTransform();
    painter->setWorldTransform(QTransform());

    // arkaplan resmine göre boyut ayarlamak;
    QSize szi(px.size().width() + 2 * distance(), px.size().height() + 2 * distance());

    QImage tmp(szi, QImage::Format_ARGB32_Premultiplied);
    QPixmap scaled = px.scaled(szi);
    tmp.fill(0);
    QPainter tmpPainter(&tmp);
    tmpPainter.setCompositionMode(QPainter::CompositionMode_Source);
    tmpPainter.drawPixmap(QPointF(-distance(), -distance()), scaled);
    tmpPainter.end();

    // blur
    QImage blurred(tmp.size(), QImage::Format_ARGB32_Premultiplied);
    blurred.fill(0);
    QPainter blurPainter(&blurred);
    qt_blurImage(&blurPainter, tmp, blurRadius(), false, true);
    blurPainter.end();

    tmp = blurred;

    // image blacken
    tmpPainter.begin(&tmp);
    tmpPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    tmpPainter.fillRect(tmp.rect(), color());
    tmpPainter.end();

    // blur shadow çizdirme;
    painter->drawImage(offset, tmp);

    // pixmap çekme ve boyutuna göre gölge çizdirme;
    painter->drawPixmap(offset, px, QRectF());

    // world transform;
    painter->setWorldTransform(restoreTransform);
}

QRectF CustomShadowEffect::boundingRectFor(const QRectF& rect) const
{
    qreal delta = blurRadius() + distance();
    return rect.united(rect.adjusted(-delta, -delta, delta, delta));
}
