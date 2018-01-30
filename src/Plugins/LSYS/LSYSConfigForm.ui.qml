import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: lsysconfigview
    width: 640
    height: 400
    property alias itvalue: itvalue
    property alias itname: itname
    property alias rulesvalue: rulesvalue
    property alias rulesname: rulesname

    Column {
        Row {
            spacing: 10

            Text {
                id: rulesname
                width: 130
                text: qsTr("Plugins.LSYS.rules")
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }

            TextInput {
                id: rulesvalue
                width: 80
                height: 20
                text: qsTr("sometext")
                font.pixelSize: 12
            }
        }
        Row {
            y: 100
            spacing: 10

            Text {
                id: itname
                width: 130
                text: qsTr("Plugins.LSYS.it")
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }

            TextInput {
                id: itvalue
                width: 80
                height: 20
                text: qsTr("sometext")
                font.pixelSize: 12
            }
        }
    }
}
