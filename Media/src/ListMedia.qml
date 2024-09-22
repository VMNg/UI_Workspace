import QtQuick 2.15

Item {
    Rectangle{
        id: listMusic
        width: 360
        height: 670
        color: "#30336b"

        ListView {
            id: listSong
            clip: true
            visible: playListSong.visible
            anchors.fill: parent
            spacing: 5
            model: playListSong

            delegate: Rectangle {
                id: elementListView
                width: 360
                height: 50
                color: "#fff2d7"

                Rectangle {
                    anchors.fill: parent
                    color: index === listSong.currentIndex ? "#7ed6df" : "#ffffff"
                    border.color: "#130f40"
                    border.width: 1

                    transitions: Transition {
                        NumberAnimation { properties: "color"; duration: 300 }
                        NumberAnimation { properties: "border.color"; duration: 300 }
                    }
                }

                Text {
                    id: textNameSong
                    height: 20
                    text: nameSong
                    color: "#f98866"
                    font.pixelSize: 20
                    font.family: "Arial"
                    anchors {
                        left: parent.left
                        verticalCenter: parent.verticalCenter
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log(index);
                        listSong.currentIndex = index;  // Cập nhật currentIndex
                        playerControl.playAtIndex(index);
                    }
                }
            }
        }

        ListView {
            id: listVideo
            clip: true
            visible: playListVideo.visible
            anchors.fill: parent
            spacing: 10
            model: playListVideo

            delegate: Rectangle {
                width: 360
                height: 50
                color: "#fff2d7"

                Rectangle {
                    anchors.fill: parent
                    color: index === listVideo.currentIndex ? "#7ed6df" : "#ffffff"
                    border.color: "#130f40"
                    border.width: 1

                    transitions: Transition {
                        NumberAnimation { properties: "color"; duration: 300 }
                        NumberAnimation { properties: "border.color"; duration: 300 }
                    }
                }

                Text {
                    id: textNameVideo
                    height: 20
                    text: nameVideo
                    color: "#f98866"
                    font.pixelSize: 20
                    font.family: "Arial"
                    anchors {
                        left: parent.left
                        verticalCenter: parent.verticalCenter
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log(index);
                        listVideo.currentIndex = index;  // Cập nhật currentIndex
                        playerControl.playAtIndex(index);
                    }
                }
            }
        }
    }

    Connections{
        target: playerControl
        function onNextMedia() {
            if (listSong.visible) {
                listSong.currentIndex += 1;
                if (listSong.currentIndex >= listSong.count) {
                    console.log("AAAA");
                    listSong.currentIndex = 0;
                }
            } else {
                listVideo.currentIndex += 1;
                if (listVideo.currentIndex >= listVideo.count) {
                    listVideo.currentIndex = 0;
                }
            }
        }
    }

    Connections{
        target: playerControl
        function onPreviousMedia() {
            if (listSong.visible) {
                listSong.currentIndex -= 1;
                if (listSong.currentIndex < 0) {
                    listSong.currentIndex = listVideo.count + 1;
                }
            } else {
                listVideo.currentIndex -= 1;
                if (listVideo.currentIndex < 0) {
                    listVideo.currentIndex = listVideo.count + 1;
                }
            }
        }
    }
}
