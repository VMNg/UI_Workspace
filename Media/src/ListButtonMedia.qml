import QtQuick 2.15

Row{
    spacing: 80

    Image {
        id: suffle
        source: status_suffle ? "qrc:/iconControlMedia/suffle_active.png" : "qrc:/iconControlMedia/suffle.png"
        width: 64
        height: 64
        MouseArea{
            anchors.fill: parent
            onClicked: {
                status_suffle = !status_suffle;
                playerControl.setShuffle(status_suffle)
            }
        }
    }
    Image {
        id: previous
        source: "qrc:/iconControlMedia/rewind-button.png"
        width: 64
        height: 64
        MouseArea{
            anchors.fill: parent
            onClicked: {
                playerControl.previous();
            }
        }
    }
    Image {
        id: play_stop
        source: status_media ? "qrc:/iconControlMedia/stop-button.png" : "qrc:/iconControlMedia/play-button-arrowhead.png"

        width: 64
        height: 64
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(status_media){
                    playerControl.pauseClicked();
                }else {
                    playerControl.playClicked();
                }
                status_media = !status_media;
            }
        }
    }
    Image {
        id: next
        source: "qrc:/iconControlMedia/forward-button.png"
        width: 64
        height: 64
        MouseArea{
            anchors.fill: parent
            onClicked: {
                playerControl.next();
            }
        }
    }
    Image {
        id: modeMedia
        source: current_list ? "qrc:/iconControlMedia/playlist-video.png" : "qrc:/iconControlMedia/playlist-song.png"
        width: 64
        height: 64
        MouseArea{
            anchors.fill: parent
            onClicked: {
                current_list = !current_list;
            }
        }
    }
}
