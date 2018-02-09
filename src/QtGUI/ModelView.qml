import QtQuick 2.7
import QtQuick.Controls 2.2
import sci.pfcrender.qnanorenderedcurve 1.0

Item{
    id : modelviewport
    anchors.fill: parent

    QNanoRenderedCurve {
        clip: false
        x : 0
        y : 0
        width: 10
        height: 10
        objectName: 'model'
        transformOrigin: Item.TopLeft
        //This will move the rendering so the top left corner of the bounding box is at (0,0), i.e. the full curve is visible
        transform : Translate{id: tr ; x: 0; y: 0}
        onBoundingBoxChanged:{
        tr.x = -newBox.x * scale;
        tr.y = -newBox.y * scale;
        scale = Math.min(
                modelviewport.width / width,
                modelviewport.height / height
                );
        }
    }
}
