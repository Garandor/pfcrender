import QtQuick 2.6
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow
{
	id: main
    visible:true
    width: 1200
    height: 900
    title: qsTr("PFCRender")

    toolBar:ToolBar
    {
        RowLayout {
            id: rowLayout
            anchors.fill: parent

            ToolButton {
                width: 100
                height: 100
                id: btnFormat
                text: "Format"
//				iconSource: "res/dummy.jpg"
                onClicked: {
                    popupContent.source = "ModelFormatConfig.qml"
                    popup.open()
                     }
            }
            ToolButton {
                width: 100
                height: 100
                id: btnImport
                text: "import"
//				iconSource: "res/dummy.jpg"
                onClicked: {
                    contentArea.source = "CreatePFCForm.ui.qml";
                     }
            }
            ToolButton {
                width: 100
                height: 100
                id: btnModify
                text: "modify"
//				iconSource: "res/dummy.jpg"
                     }
            ToolButton {
                id: b_export
                width: 100
                height: 100
                text: "export"
//                iconSource: "res/dummy.jpg"
                     }
        }

    }

    Loader{
        anchors.fill: parent
        id: contentArea
        objectName: "contentArea"
        source: "ModelView.qml"
    }

    statusBar:  StatusBar{
        RowLayout{
            anchors.fill: parent

            Label{
                text: "Status:"
            }

            Label{
                objectName: "status"
                text : ""
            }
        }

    }
    Popup {
        id: popup
        x: 100
        y: 100
        width: parent.width /2
        height: parent.height /2
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Loader{
            anchors.fill: parent
            id: popupContent
        }
    }
}
