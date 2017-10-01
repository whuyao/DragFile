#include "qfiletextedit.h"
#include <QtCore>

QFileTextEdit::QFileTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    setText("Please Drag File Here.");
    setAcceptDrops(true);
}

void QFileTextEdit::dragEnterEvent(QDragEnterEvent *ev)
{
    //if (ev->mimeData()->hasFormat("text/uri-list"))
        ev->acceptProposedAction();
}

void QFileTextEdit::dropEvent(QDropEvent *ev)
{
    QList<QUrl> urls = ev->mimeData()->urls();

    QString str;
    int i = 0;

    if (ev->mimeData()->hasFormat("text/uri-list"))
    {
        foreach (QUrl surl, urls)
        {
            QString sfilename = surl.toLocalFile().trimmed();
            if (sfilename.isEmpty()) continue;
            i++;
            str += QString("File No. %1\r\n").arg(i);
            str += getFilename(sfilename);
            str += "\r\n\r\n";
        }

        setText(str);
    }
    else
    {
        foreach (QUrl surl, urls)
        {
            QString sfilename = surl.toLocalFile().trimmed();
            if (sfilename.isEmpty()) continue;
            i++;
            str += QString("File No. %1\r\n").arg(i);
            str += sfilename;
            str += "\r\n\r\n";
        }

        setText(str);
    }

}

QString QFileTextEdit::getFilename(QString sfilename)
{
    if (!QFile::exists(sfilename))
        return "";

    QFileInfo info(sfilename);
    //
    QString abFilepath = info.absoluteFilePath();
    QString abPath = info.absolutePath();
    QString abName = info.completeBaseName();
    QString abSuffix = info.completeSuffix();

    QString str = QString("File path = %1\r\nDir path = %2\r\nFile name = %3\r\nFile suffix = %4")\
            .arg(abFilepath).arg(abPath).arg(abName).arg(abSuffix);

    return str;

}
