import QtQuick 2.15
import QtQuick.Controls
import MDA.Models 1.0
Item {
    Rectangle{
        id: listMusic
        width: 360
        height: 670
        color: "#30336b"

        ListView {
            id: listSong
            clip: true
            visible: FunctionModel.listSongController.visible
            anchors.fill: parent
            spacing: 5
            model: FunctionModel.listSongController

            delegate: Rectangle {
                id: elementListView
                width: 360
                height: 50
                color: "#fff2d7"

                Rectangle {
                    visible: !isVideoScreen
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
                        FunctionModel.setTypeMedia(true);
                        listSong.currentIndex = index;  // Cập nhật currentIndex
                        FunctionModel.playAtIndex(index);
                        isVideoScreen = false;
                    }
                }
            }
        }

        ListView {
            id: listVideo
            clip: true
            visible: FunctionModel.listVideoController.visible
            anchors.fill: parent
            spacing: 10
            model: FunctionModel.listVideoController

            delegate: Rectangle {
                width: 360
                height: 50
                color: "#fff2d7"

                Rectangle {
                    visible: isVideoScreen
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
                        FunctionModel.setTypeMedia(false);
                        listVideo.currentIndex = index;  // Cập nhật currentIndex
                        FunctionModel.playAtIndex(index);
                        isVideoScreen = true;
                    }
                }
            }
        }
    }

    Connections{
        target: FunctionModel
        function onNextMedia() {
            if (listSong.visible === true && isVideoScreen === true) {
                listVideo.currentIndex += 1;
                if (listVideo.currentIndex >= listVideo.count) {
                    listVideo.currentIndex = 0;
                }
            } else if(listSong.visible === true && isVideoScreen === false) {
                listSong.currentIndex += 1;
                if (listSong.currentIndex >= listSong.count) {
                    listSong.currentIndex = 0;
                }
            } else if(listVideo.visible === true && isVideoScreen === true) {
                listVideo.currentIndex += 1;
                if (listVideo.currentIndex >= listVideo.count) {
                    listVideo.currentIndex = 0;
                }
            } else if(listVideo.visible === true && isVideoScreen === false){
                listSong.currentIndex += 1;
                if (listSong.currentIndex >= listSong.count) {
                    listSong.currentIndex = 0;
                }
            }
        }
    }

    Connections{
        target: FunctionModel
        function onPreviousMedia() {           
            if (listSong.visible === true && isVideoScreen === true) {
                listVideo.currentIndex -= 1;
                if (listVideo.currentIndex < 0) {
                    listVideo.currentIndex = listVideo.count - 1;
                }
            } else if(listSong.visible === true && isVideoScreen === false) {
                listSong.currentIndex -= 1;
                if (listSong.currentIndex < 0) {
                    listSong.currentIndex = listSong.count - 1;
                }
            } else if(listVideo.visible === true && isVideoScreen === true) {
                listVideo.currentIndex -= 1;
                if (listVideo.currentIndex < 0) {
                    listVideo.currentIndex = listVideo.count - 1;
                }
            } else if(listVideo.visible === true && isVideoScreen === false){
                listSong.currentIndex -= 1;
                if (listSong.currentIndex < 0) {
                    listSong.currentIndex = listSong.count - 1;
                }
            }
        }
    }
    Component.onCompleted: {
        console.log("listSong visible: ", FunctionModel.listSongController.visible);
        console.log("listVideo visible: ", FunctionModel.listVideoController.visible);
    }
}
