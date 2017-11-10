import QtQuick 2.7
import QtQuick.Controls 2.2
import sci.pfcrender.customModel 1.0

Rectangle{
    border.width: 1
    border.color: "blue"
    anchors.fill: parent


    Flickable{
        clip: false
        anchors.fill: parent
        contentWidth: model.width
        contentHeight: model.height

        PinchArea
        {
        anchors.fill: parent
        objectName: "ModelContainer"
        enabled: true
        pinch.target : model
        onPinchUpdated:{
                model.scale = 2
                console.log("something")
        }
        }
        MouseArea {
        anchors.fill: parent
        onWheel: {
            if (wheel.modifiers & Qt.ControlModifier) {
            model.scale = 1+ (wheel.angleDelta.y / 120);
            }
        }
        }

        Rectangle
        {
            border.color: "#00ec37"
            anchors.fill: parent
        }

        CustomGeometryModel {
        width: 10
        height: 20
        objectName: 'model'
        id: model
        }

    }

}
