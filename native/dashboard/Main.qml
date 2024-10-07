import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Window {
    visible: true
    color: "#2c4669"
    property string selectedOptionGear: ""

    Rectangle{
        anchors{
            top: parent.top
            topMargin: 10
            left: parent.left
            leftMargin: 50
            right: parent.right
            rightMargin: 50
            bottom: parent.bottom
            bottomMargin: 50
        }
        color: "#1E3A5F"

        GridLayout{
            id: grid
            anchors.fill: parent
            columns: 5
            rows: 3
            columnSpacing: 5
            rowSpacing: 5

            Rectangle{
                id: speed

                color: "#3c4b6c"
                Layout.preferredWidth: 50
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.rowSpan: 2

                Column{
                    id: speedColumn
                    spacing: 30
                    anchors.fill:parent
                    Text{
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 30
                        id: txtSpeed
                        text: "Speed"
                        color: "white"
                    }
                    Rectangle {
                        width: 200
                        height: 200
                        radius: 180
                        border.color: "#80FF00"
                        color: "#3c4b6c"

                        anchors.horizontalCenter: parent.horizontalCenter

                        Column{
                            anchors.centerIn: parent
                            spacing: 10
                            Text{
                                font.pixelSize: 30
                                color: "white"
                                text: "200"
                            }
                            Text{
                                font.pixelSize: 30
                                color: "white"
                                text: "Km/h"
                            }
                        }
                    }
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 30
                        text: "ODO"
                        color: "white"
                    }
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 30
                        text: "2024101 Km"
                        color: "white"
                    }
                }
            }

            Rectangle {
                id: gear

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 25
                Layout.preferredHeight: 50
                Layout.rowSpan: 2

                Column {
                    spacing: 20
                    anchors.centerIn: parent

                    Text {
                        text: "Gear"
                        font.pixelSize: 30
                        color: "white"
                    }

                    Repeater {
                        model: ["P", "D", "N", "R"]
                        delegate: Text {
                            text: modelData
                            font.bold: true
                            font.pixelSize: 45
                            color: (selectedOptionGear === modelData) ? "#80FF00" : "grey"
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    selectedOptionGear = modelData;
                                }
                            }
                        }
                    }
                }
            }
            Rectangle{
                id: doorLock

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumWidth: grid.width - gear.width - speed.width
                Layout.preferredHeight: 100
                Layout.columnSpan: 3
                Column{
                    id: columnMedia
                    anchors.centerIn: parent
                    spacing: 30
                    Text{
                        id:txtSong
                        anchors.horizontalCenter: columnMedia.horizontalCenter
                        text: funcProvider.songReceive
                        color: "#80FF00"
                        font.pixelSize:40
                    }
                    Row{
                        spacing: 30
                        anchors.horizontalCenter: columnMedia.horizontalCenter
                        Image {
                            id: suffle
                            opacity: 0.7
                            source: "qrc:/iconControlMedia/suffle.png"
                            width: 64
                            height: 64
                        }
                        Image {
                            id: previous
                            opacity: 0.7
                            source: "qrc:/iconControlMedia/rewind-button.png"
                            width: 64
                            height: 64
                        }
                        Image {
                            id: play_stop
                            opacity: 0.7
                            source:funcProvider.statePlay ? "qrc:/iconControlMedia/stop-button.png" :"qrc:/iconControlMedia/play-button-arrowhead.png"
                            width: 64
                            height: 64
                        }
                        Image {
                            id: next
                            opacity: 0.7
                            source: "qrc:/iconControlMedia/forward-button.png"
                            width: 64
                            height: 64
                        }
                        Image {
                            id: modeMedia
                            opacity: 0.7
                            source:"qrc:/iconControlMedia/playlist-song.png"
                            width: 64
                            height: 64
                        }
                    }
                }

            }
            Rectangle{

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Text {
                    id: inside
                    text: "Inside"
                    font.pixelSize: 30
                    color: "white"
                    anchors{
                        top: parent.top
                        topMargin: 10
                        left: parent.left
                        leftMargin: 50
                    }
                }
                Text {
                    id: temp
                    text: ClimateModel.temp
                    font.pixelSize: 70
                    color: "#80FF00"
                    anchors{
                        bottom: parent.bottom
                        bottomMargin: 15
                        left: inside.left
                    }
                }
                Text {
                    id: degree
                    text: "°C"
                    font.pixelSize: 40
                    color: "#80FF00"
                    anchors{
                        bottom: parent.bottom
                        bottomMargin: 20
                        right: parent.right
                        rightMargin: 50
                    }
                }

            }
            Rectangle{
                id: fuel

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
                Layout.columnSpan: 2

                Column {
                    anchors.fill: parent
                    spacing: 5

                    Text {
                        topPadding: 10
                        text: "Fuel"
                        font.pixelSize: 30
                        color: "white"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Row {
                        width: parent.width
                        anchors {
                            left: parent.left
                            centerIn : parent
                        }
                        leftPadding: 100
                        spacing: 20

                        Text {
                            text: "N"
                            font.pixelSize: 30
                            color: "white"
                        }

                        Rectangle {
                            id: fuelLevel
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width * 0.5
                            height: 20
                            color: "#80FF00"
                            radius: 3
                        }

                        Text {
                            text: "F"
                            font.pixelSize: 30
                            color: "white"
                        }
                    }
                }
            }

            Rectangle{
                id: ac

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 3

                property int level: ClimateModel.fanLv

                Text {
                    id: mode
                    text: "A/C mode"
                    font.pixelSize: 30
                    color: "white"
                    topPadding: 10
                    anchors{
                        right: parent.right
                        rightMargin: 180
                    }
                }
                GridLayout {
                    id: imageGrid

                    columns: 4
                    rowSpacing: 10
                    columnSpacing: 20
                    anchors{
                        top: mode.bottom
                        topMargin: 10
                        left: mode.left
                        leftMargin: -5
                    }

                    Repeater {
                        model: ListModel {
                            ListElement { type: "seat-heater-L"; activeImage: "qrc:/iconClimate/active-seat-L.png" ; inactiveImage: "qrc:/iconClimate/seat-heater-L.png" }
                            ListElement { type: "seat-heater-R"; activeImage: "qrc:/iconClimate/active-seat-R.png" ; inactiveImage: "qrc:/iconClimate/seat-heater-R.png" }
                            ListElement { type: "front"; activeImage: "qrc:/iconClimate/front-defrost.png" ; inactiveImage: "qrc:/iconClimate/defrost.png" }
                            ListElement { type: "rear"; activeImage: "qrc:/iconClimate/rear-active.png" ; inactiveImage: "qrc:/iconClimate/rear.png" }
                        }

                        delegate: Image {
                            source: {
                                if((model.type === "seat-heater-R" && ClimateModel.seatHeaterRStatus) ||(model.type === "seat-heater-L" && ClimateModel.seatHeaterLStatus) ||
                                (model.type === "front" && ClimateModel.frontStatus)|| (model.type === "rear" && ClimateModel.rearStatus)){
                                    return model.activeImage;
                                }
                                else{
                                    return model.inactiveImage;
                                }
                            }
                            width: 40
                            height: 40
                        }
                    }
                }

                Text {
                    id: acText
                    text: "A/C"
                    font.pixelSize: 30
                    color: "white"
                    topPadding: 10
                    anchors{
                        left: parent.left
                        leftMargin: 30
                    }
                }
                Image{
                    id: acImage
                    source : "qrc:/iconClimate/fan_active.png"
                    anchors{
                        top: acText.bottom
                        topMargin: 15
                        left: acText.left
                        leftMargin: -5
                    }
                    width: 55
                    height: 55
                }
                Row {
                    id: acControl
                    anchors{
                        bottom : parent.bottom
                        bottomMargin: 33
                        left: parent.left
                        leftMargin: 80
                    }
                    spacing: 4
                    Repeater {
                        model: 25

                        Rectangle {
                            width: 5
                            height: 5 + index * 1.15
                            color: {
                                if (ac.level === -1) {
                                    return "lightgray";
                                }
                                else if (ac.level === 0) {
                                    // return "lightgreen";
                                }
                                else if (ac.level >= 1 && ac.level <= 5) {
                                    return (index < (ac.level*5)) ? "lightgreen" : "lightgray";
                                }
                                else {
                                    return "lightgray";
                                }
                            }
                            radius: 3
                            anchors{
                                bottom: parent.bottom
                            }
                        }
                    }
                }
            }

            Rectangle{
                id: light

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Text {
                    text: "Light"
                    font.pixelSize: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    topPadding: 10
                    color: "white"
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    topPadding: 50
                    spacing: 50

                    Image {
                        id: nearLight
                        source: "qrc:/iconDashboard/NearOff.png"
                        width: 50
                        height: 50
                        property bool isActive: false
                        z: 9999
                        MouseArea {
                            anchors.fill: parent
                            onReleased:  {
                                console.log("Current source:", nearLight.source);
                                if (nearLight.isActive === true) {
                                    nearLight.source = "qrc:/iconDashboard/NearOn.png"
                                    nearLight.isActive = false
                                } else {
                                    nearLight.source = "qrc:/iconDashboard/NearOff.png"
                                    nearLight.isActive = true
                                }
                            }
                        }
                    }

                    Image {
                        id: farLight
                        source: nearLight.isActive ? "qrc:/iconDashboard/FarOn.png" : "qrc:/iconDashboard/FarOff.png"
                        width: 50
                        height: 50
                    }
                }
            }
            Rectangle{
                id: seatBelt

                color: "#3c4b6c"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Column {
                    anchors.fill: parent
                    spacing: 20
                    anchors.centerIn: parent

                    Text {
                        text: "Seat belts"
                        font.pixelSize: 30
                        color: "white"
                        topPadding: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Image {
                        source: "qrc:/iconDashboard/seat-belt.png"
                        opacity: 0.6
                        width: 50
                        height: 50
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }
    }
}
