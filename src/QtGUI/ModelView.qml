import QtQuick 2.7
import QtQuick.Controls 2.2


Flickable{
    clip: false
    width: 500
    height: 600
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


    Image{
    id: model
    source: "qrc:///res/eucalyptus.jpg"
}

}
