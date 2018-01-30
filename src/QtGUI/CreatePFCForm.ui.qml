import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: window
    width: 400
    height: 400
    property alias bExport: bExport
    property alias listView: listView

    ListView {
        id: listView
        x: 0
        y: -355
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
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
                width: 415
                height: 48
                spacing: 10
                Button {
                    id: bDel
                    width: 40
                    height: parent.Button
                    text: "del"
                    Image {
                        source: "res/dummy.jpg"
                    }
                }
                Button {
                    id: bUp
                    width: 40
                    height: parent.height
                    text: "up"
                    Image {
                        source: "res/dummy.jpg"
                    }
                }
                Button {
                    id: bDown
                    width: 40
                    height: parent.height
                    text: "down"
                    Image {
                        source: "res/dummy.jpg"
                    }
                }
                Item {
                    id: item1
                    height: 200
                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    anchors.left: bDown.right
                    anchors.leftMargin: 10
                }

            }
        }
    }

    Row {
        id: row
        x: 0
        y: -355
        width: 400
        height: 45
        anchors.top: parent.top
        anchors.topMargin: 0

        Button {
            id: bImport
            width: 94
            height: 22
            text: qsTr("import")
            checked: false
            checkable: false
        }

        Button {
            id: bModify
            width: 94
            height: 22
            text: qsTr("modify")
        }
        Button {
            id: bExport
            width: 94
            height: 22
            text: qsTr("export")
        }
    }
}
