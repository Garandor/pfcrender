import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    width: 640
    height: 400
    property alias seglen: seglen

    Column {
        Row {
            id: seglen
            spacing: 10

            Text {
                id: name
                width: 130
                text: qsTr("Segment Length:")
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }

            TextInput {
                id: value
                width: 80
                height: 20
                text: qsTr("10")
                font.pixelSize: 12
            }
        }
    }
}
