#ifndef QFILETEXTEDIT_H
#define QFILETEXTEDIT_H

#include <QTextEdit>
#include <QString>
#include <QDropEvent>
#include <QDragEnterEvent>

class QFileTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit QFileTextEdit(QWidget *parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent* ev);
    void dropEvent(QDropEvent *ev);

private:
    QString getFilename(QString sfilename);

};

#endif // QFILETEXTEDIT_H
