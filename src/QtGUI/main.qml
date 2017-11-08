import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0

ApplicationWindow
{
	id: main
    visible:true
    width: 800
    height: 600

    toolBar: ToolBar
    {}

    ModelView
    {

    }

    statusBar:  StatusBar{
        RowLayout{
            anchors.fill: parent

            Label{
                text: "Status: "
            }

            Label{
                objectName: "status"
                text : ""
            }
        }

    }
}
