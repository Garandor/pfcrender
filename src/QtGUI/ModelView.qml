import QtQuick 2.7
import QtQuick.Controls 2.2
import sci.pfcrender.qnanorenderedcurve 1.0

Item{
    id : modelviewport
    anchors.fill: parent

        MouseArea {
        anchors.fill: parent
        propagateComposedEvents: true
        onWheel: {
            if (wheel.modifiers & Qt.ControlModifier) {
                    sc.yScale = sc.yScale+ (wheel.angleDelta.y / 2400);
                    if (sc.yScale < 0) sc.yScale = 0.01;
                    console.log("set scale to "+sc.yScale+" wheel: "+wheel.angleDelta.y);
            console.log (modelviewport.width+" "+model.width+" "+modelviewport.height+" "+model.height );
            }
        }
        }


        Rectangle
        {
            id:bbox
            width: model.width
            height: model.height
            border.color: "red"
            border.width: 4

//                transform:[Translate{x:20;y:30},
//                    Scale{id:sc;xScale: yScale;origin.x:-0;origin.y:-0}]


       QNanoRenderedCurve {
            clip: false
            x : 0
            y : 0
            width: 10
            height: 10
            objectName: 'model'
            transformOrigin: Item.TopLeft
            id: model
            //This will move the rendering so the top left corner of the bounding box is at (0,0), i.e. the full curve is visible
            transform : [
                Translate{id: tr ; x: 0; y: 0}]
//                Scale{id:sc;origin.x: -0; origin.y: -0;xScale: yScale}]
            onBoundingBoxChanged:{
                tr.x = -newBox.x * scale;
                tr.y = -newBox.y * scale;
                scale = Math.min(
                            modelviewport.width / width,
                            modelviewport.height / height
                            );

                console.log(model.transformOriginPoint);

            }
                onScaleChanged: {
                    width = width * scale;
                    height = height * scale;
                }
        }
        }
}
