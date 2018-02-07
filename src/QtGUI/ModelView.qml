import QtQuick 2.7
import QtQuick.Controls 2.2
import sci.pfcrender.customModel 1.0
import sci.pfcrender.qnanorenderedcurve 1.0

Rectangle{
    border.width: 4
    id : modelviewport
    border.color: "blue"
    anchors.fill: parent
//    anchors.centerIn: parent

    PinchArea
    {
    anchors.fill: parent
    enabled: true
    pinch.target : model
    onPinchUpdated:{
//        model.scale = 2
        console.log("pinch")
    }
    }

    Flickable{
        clip: true
        anchors.fill: parent
        contentWidth: model.width
        contentHeight: model.height


        Rectangle
        {
            border.color: "#00ec37"
            anchors.fill: parent
        }

        MouseArea {
        anchors.fill: parent
        propagateComposedEvents: true
        onWheel: {
            if (wheel.modifiers & Qt.ControlModifier) {
                    model.scale = model.scale + (wheel.angleDelta.y / 2400);
                    if (model.scale < 0) model.scale = 0.01;
                    console.log("set scale to "+model.scale+" wheel: "+wheel.angleDelta.y)
            console.log (modelviewport.width+" "+model.width+" "+modelviewport.height+" "+model.height )
            }
        }
        }

       QNanoRenderedCurve {
            width: 1000
            height: 1000
        objectName: 'model'
        id: model
        onScaleChanged: {
            width = vertexSize.width * scale;
            height = vertexSize.height * scale;
            parent.returnToBounds
        }
        }
    }

}
