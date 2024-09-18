import QtQuick 2.15
import QtQuick.Controls

//============================== AC FUNCTION ==========================

Item {
    width: 248
    height: 56
    ListView {
        id: listView
        width: parent.width
        height: parent.height
        orientation: ListView.Horizontal
        anchors.centerIn: parent
        interactive: false

        model: ListModel {
            ListElement {
                name: "AC"
                srcPath: "qrc:/ui/HVACScreen/IconPic/air-conditioner.png"
            }

            ListElement {
                name: "Front"
                srcPath: "qrc:/ui/HVACScreen/IconPic/front-defrost.png"
            }

            ListElement {
                name: "Rear"
                srcPath: "qrc:/ui/HVACScreen/IconPic/rear-defrost.png"
            }

            ListElement {
                name: "Recirculation"
                srcPath: "qrc:/ui/HVACScreen/IconPic/recirculated.png"
            }
        }

        /*Display the amount of button based on the number of list element*/
        delegate: Item {
            Column {
                Rectangle {
                    id: recInButton
                    anchors.fill: parent
                    radius: 5
                    border.width: 1
                    color: "white"

                    /*Animation when a button is clicked, will be played in the onClicked function*/
                    SequentialAnimation on color {
                      id: chooseAirFlowAnimation
                      ColorAnimation { to: "#33000000"; duration: 50 }
                      ColorAnimation { to: "white"; duration: 50 }
                      running: false
                    }

                    /*State of a button, after clicked once, the button will change its state to "stateOn" and vice versa*/
                    states: [
                        State {
                            name: "stateOn"
                            PropertyChanges { target: recInButton; border.color: "green"; border.width: 3; radius: 5;}
                        },
                        State {
                            name: "stateOff"
                            PropertyChanges { target: recInButton; border.width: 0; }
                        }
                    ]

                    /*Used to load the data from the ini file, and changed the state of those buttons accordingly*/
                    Component.onCompleted: {
                        if (name == "AC")
                        {
                            if(datasHVAC.getValue("acFunctions", "acFunctions1") === "true")
                            {
                                recInButton.state = "stateOn"
                            }
                            else if (datasHVAC.getValue("acFunctions", "acFunctions1") === "false")
                            {
                                recInButton.state = "stateOff"
                            }
                        }
                        if (name == "Front")
                        {
                            if(datasHVAC.getValue("acFunctions", "acFunctions2") === "true")
                            {
                                recInButton.state = "stateOn"
                            }
                            else if (datasHVAC.getValue("acFunctions", "acFunctions2") === "false")
                            {
                                recInButton.state = "stateOff"
                            }
                        }
                        if (name == "Rear")
                        {
                            if(datasHVAC.getValue("acFunctions", "acFunctions3") === "true")
                            {
                                recInButton.state = "stateOn"
                            }
                            else if (datasHVAC.getValue("acFunctions", "acFunctions3") === "false")
                            {
                                recInButton.state = "stateOff"
                            }
                        }
                        if (name == "Recirculation")
                        {
                            if(datasHVAC.getValue("acFunctions", "acFunctions4") === "true")
                            {
                                recInButton.state = "stateOn"
                            }
                            else if (datasHVAC.getValue("acFunctions", "acFunctions4") === "false")
                            {
                                recInButton.state = "stateOff"
                            }
                        }
                    }

                    /*Mouse area to allow clicking on the button, allowing the button to change state and its current state to be saved into the ini file.
                    */
                    MouseArea {
                        id: mouseAreax
                        anchors.fill: parent
                        Connections {
                            target: mouseAreax
                            function onClicked(){
                                if (name == "AC")
                                {
                                    if (recInButton.state === "stateOn")
                                    {
                                        recInButton.state = "stateOff"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions1(false)
                                    } else {
                                        recInButton.state = "stateOn"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions1(true)
                                    }
                                }
                                else if (name == "Front")
                                {
                                    if (recInButton.state === "stateOn")
                                    {
                                        recInButton.state = "stateOff"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions2(false)
                                    } else {
                                        recInButton.state = "stateOn"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions2(true)
                                    }
                                }
                                else if (name == "Rear")
                                {
                                    if (recInButton.state === "stateOn")
                                    {
                                        recInButton.state = "stateOff"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions3(false)

                                    } else {
                                        recInButton.state = "stateOn"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions3(true)
                                    }
                                }
                                else if (name == "Recirculation")
                                {
                                    if (recInButton.state === "stateOn")
                                    {
                                        recInButton.state = "stateOff"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions4(false)
                                    } else {
                                        recInButton.state = "stateOn"
                                        chooseAirFlowAnimation.start()

                                        settingsHVAC.setAcFunctions4(true)
                                    }
                                }
                            }
                        }
                    }
                }

                /*Display an image inside the button, the source of this image is declared in list element*/
                Image {
                    source: srcPath
                    height: 30
                    width: 30
                    anchors.horizontalCenter: recInButton.horizontalCenter
                    anchors.verticalCenter: recInButton.verticalCenter
                }

            anchors.fill: parent
            }
            width: listView.width / 4
            height: listView.height
        }
    }
}
