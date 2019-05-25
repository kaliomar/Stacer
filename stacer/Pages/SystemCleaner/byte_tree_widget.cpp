#include "byte_tree_widget.h"

void ByteTreeWidget::setValues(const QString &text, const quint64 &size, const QVariant &data) {
    this->setText(0, text);
    this->setText(1, FormatUtil::formatBytes(size));
    this->setData(1, 0x0100, size);
    this->setData(2, 0, data);
    this->setCheckState(0, Qt::Unchecked);
}

bool ByteTreeWidget::operator<(const QTreeWidgetItem &other) const
{
    int column = treeWidget()->sortColumn();
    // sort by bytes
    if(column == 1) {
        return this->data(1, 0x0100) < other.data(1, 0x0100);
    }
    // default sorting
    return text(column).toLower() < other.text(column).toLower();
}
