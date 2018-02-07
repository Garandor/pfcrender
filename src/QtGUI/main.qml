import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow
{
	id: main
    visible:true
    width: 800
    height: 600
    title: qsTr("PFCRender")

    toolBar:ToolBar
    {
        RowLayout {
            id: rowLayout
            anchors.fill: parent

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
                width: 10
                height: 10
                id: btnModify
                text: "modify"
//				iconSource: "res/dummy.jpg"
                     }
            ToolButton {
                id: b_export
                width: 10
                height: 10
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
}
