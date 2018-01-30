import QtQuick 2.4
//import Sci.Pfcrender.Common.Config_Registry 1.0

LSYSConfigForm {
    
    onDataChanged: {
        console.log("asdf"+Config_Registry.getOpt("ViewModel.Angle"))
    }
    
//  for(var i=0; i<MyListView.count; i++)
//  {
//     MyListView.children[i].my_text.color = "red"
//  }
     
}
