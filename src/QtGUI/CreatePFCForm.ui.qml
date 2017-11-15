import QtQuick 2.4

Item {
    width: 400
    height: 400

    Flickable {
        id: flickable
        anchors.top: row.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 0
    }

    Row {
        id: row
        x: 0
        y: 0
        width: 400
        height: 45
    }
}
