#ifndef WIDGET_MANA_H
#define WIDGET_MANA_H

#include <QWidget>

namespace Ui {
class widget_mana;
}

class widget_mana : public QWidget
{
    Q_OBJECT

public:
    explicit widget_mana(QWidget *parent = nullptr);
    ~widget_mana();

private:
    Ui::widget_mana *ui;
};

#endif // WIDGET_MANA_H
