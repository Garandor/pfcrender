import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    width: 640
    height: 400

    ListView {
        id: listView
        x: 181
        y: 14
        width: 110
        height: 160
        anchors.fill: parent
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                spacing: 10

                Text {
                    id: name
                    text: qsTr("#name#")
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }

                TextInput {
                    id: value
                    width: 80
                    height: 20
                    text: qsTr("Text Input")
                    font.pixelSize: 12
                }
            }
        }
        model: ListModel {
            ListElement {
                name: "Rules"
                value: "sometext"
                ToolTip.visible: down
                ToolTip.text: "hi"
            }
            ListElement {
                name: "iterates"
                value: "sometext"
                ToolTip.visible: hovered
                ToolTip.text: "ho"
            }
            ListElement {
                name: "Initial Angle"
                value: "sometext"
                ToolTip.visible: hovered
                ToolTip.text: "oas"
            }
            ListElement {
                name: "Angle Increment"
                value: "sometext"
                ToolTip.visible: hovered
                ToolTip.text: "oas"
            }
            ListElement {
                name: "Segment Length"
                value: "sometext"
                ToolTip.visible: hovered
                ToolTip.text: "oas"
            }
            ListElement {
                name: "Segment Width"
                value: "sometext"
                ToolTip.text: "oas"
                ToolTip.visible: hovered
            }
        }
    }
}
