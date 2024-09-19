import QtQuick 2.15

Item {
    Rectangle {
        id: listMusic
        width: 360
        height: 670
        color: "#30336b"
        ListView{
            id:listSong
            clip: true
            visible: playListSong.visible
            anchors.fill: parent
            spacing: 5
            model: playListSong
            delegate:
                Rectangle{
                width: 360
                height: 50
                color: "#fff2d7"
                Text {
                    id: textNameSong
                    height: 20
                    text: nameSong
                    color: "#f98866"
                    font.pixelSize: 20
                    font.family: "Arial"
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked:{
                        console.log(index);
                        playerControl.playAtIndex(index);

                    }
                }
            }
        }
        ListView{
            id:listVideo
            clip: true
            visible: playListVideo.visible
            anchors.fill: parent
            spacing: 10
            model: playListVideo
            delegate:
                Rectangle{
                width: 360
                height: 50
                color: "#fff2d7"
                Text {
                    id: textNameVideo
                    height: 20
                    text: nameVideo
                    color: "#f98866"
                    font.pixelSize: 20
                    font.family: "Arial"
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked:{
                        console.log(index);
                        playerControl.playAtIndex(index);
                    }
                }
            }
        }
    }
}
