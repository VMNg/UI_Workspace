import QtQuick 2.15
import QtQuick.Controls

//============================== AC FUNCTION ==========================

Item {
    width: 248
    height: 60

    ButtonFunction {
        id: rear

        anchors{
            right: parent.right
            top: parent.top
        }
        sourceFunction: {
            if(active === false){
                return "qrc:/image/rear.png"
            }
            else{
                return "qrc:/image/rear-active.png"
            }
        }
        textFunction: "Rear"
    }

    ButtonFunction {
        id: front

        anchors{
            right: rear.left
            rightMargin: 105
        }
        sourceFunction: {
            if(active === false){
                return "qrc:/image/defrost.png"
            }
            else{
                return "qrc:/image/front-defrost.png"
            }
        }
        textFunction: "Front"
    }

    ButtonFunction {
        id: seatHeaterL

        anchors{
            right: front.left
            rightMargin: 105
        }
        sourceFunction: {
            if(seatHeaterL.clickCount === 0){
                return "qrc:/image/seat-heater-L.png"
            }
            else{
                return "qrc:/image/active-seat-L.png"
            }
        }

        ListView {
            id: listViewL
            width: 50
            height: 30
            anchors{
                top : parent.bottom
                topMargin: 5
                left: parent.left
                leftMargin: 5
            }
            spacing: 5
            orientation: ListView.Horizontal

            model: ListModel {
                ListElement { color: "#808080" }
                ListElement { color: "#808080" }
                ListElement { color: "#808080" }
            }

            delegate: Rectangle {
                width: 15
                height: 15
                color: model.color
                border.color: "black"
                border.width: 1
                radius: 5
            }
        }
        onClicked:{
            if (seatHeaterL.clickCount === 1) {
               listViewL.model.setProperty(0, "color", "orange");
            } else if (seatHeaterL.clickCount === 2) {
                listViewL.model.setProperty(1, "color", "orange");
            } else if (seatHeaterL.clickCount === 3) {
               listViewL.model.setProperty(2, "color", "orange");
            } else {
               listViewL.model.setProperty(0, "color", "#808080");
               listViewL.model.setProperty(1, "color", "#808080");
               listViewL.model.setProperty(2, "color", "#808080");
               seatHeaterL.clickCount = 0;
            }
        }
    }

    ButtonFunction {
        id: angelSeat

        activeButton : true
        anchors{
            left: parent.right
            leftMargin: 310
            top: parent.top
        }
        sourceFunction: "qrc:/image/Angel.png"
        textFunction: "Angle"
    }

    ButtonFunction {
        id: moveSeat

        activeButton : true
        anchors{
            left: angelSeat.right
            leftMargin: 105
        }
        sourceFunction: "qrc:/image/move.png"
        textFunction: "Move"
    }

    ButtonFunction {
        id: seatHeaterR

        anchors{
            left: moveSeat.right
            leftMargin: 105
        }
        sourceFunction: {
            if(seatHeaterR.clickCount === 0){
                return "qrc:/image/seat-heater-R.png"
            }
            else{
                return "qrc:/image/active-seat-R.png"
            }
        }

        ListView {
            id: listViewR
            width: 50
            height: 30
            anchors{
                top : parent.bottom
                topMargin: 5
                left: parent.left
                leftMargin: 4
            }
            spacing: 5
            orientation: ListView.Horizontal

            model: ListModel {
                ListElement { color: "#808080" }
                ListElement { color: "#808080" }
                ListElement { color: "#808080" }
            }

            delegate: Rectangle {
                width: 15
                height: 15
                color: model.color
                border.color: "black"
                border.width: 1
                radius: 5
            }
        }

        onClicked:{
            if (seatHeaterR.clickCount === 1) {
               listViewR.model.setProperty(0, "color", "orange");
            } else if (seatHeaterR.clickCount === 2) {
                listViewR.model.setProperty(1, "color", "orange");
            } else if (seatHeaterR.clickCount === 3) {
               listViewR.model.setProperty(2, "color", "orange");
            } else {
               listViewR.model.setProperty(0, "color", "#808080");
               listViewR.model.setProperty(1, "color", "#808080");
               listViewR.model.setProperty(2, "color", "#808080");
               seatHeaterR.clickCount = 0;
            }
        }
    }
}
