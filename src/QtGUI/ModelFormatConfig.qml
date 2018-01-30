import QtQuick 2.4
import QtQuick.Dialogs 1.3

Item{
ModelFormatConfigForm {

}


ColorDialog {
    id: colorDialog
    title: "Please choose a color"
    onAccepted: {
        console.log("You chose: " + colorDialog.color)
    }
    onRejected: {
        console.log("Canceled")
    }
}

}
