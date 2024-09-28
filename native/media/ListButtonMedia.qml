import QtQuick 2.15
import QtQuick.Controls
import MDA.Models 1.0
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
                FunctionModel.setShuffle(status_suffle)
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
                FunctionModel.previous();
            }
        }
    }
    Image {
        id: play_stop
        source: FunctionModel.start ? "qrc:/iconControlMedia/stop-button.png" : "qrc:/iconControlMedia/play-button-arrowhead.png"

        width: 64
        height: 64
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(FunctionModel.start){
                    FunctionModel.pauseClicked();
                    if(isVideoScreen === false){
                        isPauseMusic = true;
                    }
                    functionModelInterface.sendPlayState(FunctionModel.start)
                }else {
                    FunctionModel.playClicked();
                    if(isVideoScreen === false){
                        isPauseMusic = false;
                    }
                    functionModelInterface.sendPlayState(FunctionModel.start)
                }
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
                FunctionModel.next();
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
                if(current_list === false){
                    FunctionModel.listSongController.setVisibleUI(false);
                    FunctionModel.listVideoController.setVisibleUI(true);
                    // FunctionModel.setTypeMedia(false);
                }else {
                    FunctionModel.listSongController.setVisibleUI(true);
                    FunctionModel.listVideoController.setVisibleUI(false);
                    // FunctionModel.setTypeMedia(true);
                }
                current_list = !current_list;
            }
        }
    }
}
