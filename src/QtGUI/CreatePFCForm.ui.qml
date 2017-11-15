import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: window
    width: 400
    height: 400
    property alias listView: listView

    Flickable {
        id: flickable
        anchors.top: row.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 0

        ListView {
            id: listView
            anchors.fill: parent
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    spacing: 10
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
        }
    }

    Row {
        id: row
        x: 0
        y: 0
        width: 400
        height: 45

        Button {
            id: button
            width: 94
            height: 22
            text: qsTr("import")
            checked: false
            checkable: false
        }

        Button {
            id: button1
            width: 94
            height: 22
            text: qsTr("modify")
        }
        Button {
            id: button2
            width: 94
            height: 22
            text: qsTr("export")
        }
    }
}
