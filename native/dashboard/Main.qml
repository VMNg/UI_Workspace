import QtQuick
import QtQuick.Layouts
Window {
    visible: true
    color: "#1E3A5F"
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
                border.width: 2
                border.color: "white"
                color: "transparent"
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
                        color: "transparent"
                        border.width: 2
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
                border.width: 2
                border.color: "white"
                color: "transparent"
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
                border.width: 2
                border.color: "white"
                color: "transparent"
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
                border.width: 2
                border.color: "white"
                color: "transparent"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Text {
                    id: inside
                    text: "Inside"
                    font.pixelSize: 30
                    color: "orange"
                    anchors{
                        top: parent.top
                        topMargin: 10
                        left: parent.left
                        leftMargin: 50
                    }
                }
                Text {
                    id: temp
                    text: tempModel.temp
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
                color: "transparent"
                border.width: 2
                border.color: "white"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
                Layout.columnSpan: 2

                Column {
                    anchors.fill: parent
                    spacing: 5

                    Text {
                        topPadding: 20
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
                id: infoAC
                border.width: 2
                border.color: "white"
                color: "transparent"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 3
            }
            Rectangle{
                id: light
                border.width: 2
                border.color: "white"
                color: "transparent"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Text {
                    text: "Light"
                    font.pixelSize: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "white"
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    topPadding: 30
                    spacing: 30

                    Image {
                        id: nearLight
                        source: "qrc:/iconDashboard/NearOn.png"
                        width: 64
                        height: 64
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if (nearLight.source === "qrc:/iconDashboard/NearOn.png") {
                                    nearLight.source = "qrc:/iconDashboard/NearOff.png";
                                } else {
                                    nearLight.source = "qrc:/iconDashboard/NearOn.png";
                                }
                            }
                        }
                    }

                    Image {
                        id: farLight
                        source: "qrc:/iconDashboard/FarOn.png"
                        width: 64
                        height: 64
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if (farLight.source === "qrc:/iconDashboard/FarOn.png") {
                                    farLight.source = "qrc:/iconDashboard/FarOff.png";
                                } else {
                                    farLight.source = "qrc:/iconDashboard/FarOn.png";
                                }
                            }
                        }
                    }
                }
            }
            Rectangle{
                id: seatBelt
                border.width: 2
                border.color: "white"
                color: "transparent"
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.preferredHeight: 50
            }
        }
    }
}
