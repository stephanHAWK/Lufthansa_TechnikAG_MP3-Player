#ifndef HOVERFILTER_H
#define HOVERFILTER_H

#include "qwidget.h"
#include <QObject>

#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QPropertyAnimation>

class HoverFilter : public QObject {
    Q_OBJECT

public:
    HoverFilter(QObject *parent = nullptr) : QObject(parent) {}

protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        if (event->type() == QEvent::Enter)
        {
            // Maus betritt das Item
            if (obj->isWidgetType())
            {
                QWidget *widget = qobject_cast<QWidget *>(obj);

                // Check if the widget has text and if it's too long
                if (widget->inherits("QLabel")) // You can adjust this condition based on the actual type of your widget
                {
                    QLabel *label = qobject_cast<QLabel *>(widget);
                    QString text = label->text();

                    QPropertyAnimation *animation = new QPropertyAnimation(label, "pos");
                    animation->setDuration(1000); // Set the duration of the animation in milliseconds
                    animation->setStartValue(label->pos());
                    animation->setEndValue(label->pos() + QPoint(50, 0)); // Adjust the destination position

                    // Start the animation
                    animation->start(QAbstractAnimation::DeleteWhenStopped);
                }

                // Set the style sheet for hover
                widget->setStyleSheet("background-color: #99a7bf; border: 1px solid red;");
            }
        }
        else if (event->type() == QEvent::Leave)
        {
            // Maus verlässt das Item
            if (obj->isWidgetType())
            {
                QWidget *widget = qobject_cast<QWidget *>(obj);
                widget->setStyleSheet(""); // Zurücksetzen zum ursprünglichen Stylesheet
            }
        }

        return false;
    }
};

#endif // HOVERFILTER_H
