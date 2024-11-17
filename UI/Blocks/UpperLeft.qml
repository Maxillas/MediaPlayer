import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.platform
import "../Components"

Rectangle {
  id: root

  ColumnLayout {
    Rectangle {
      id: spacer
      width: root.width
      height: 20
      color: transparentColor
    }

    FileDialog {
      id: open_playlist_dialog
      title: "Open playlist"
      visible: false
      fileMode: FileDialog.OpenFile
      onAccepted: {
        console.log("open playlist")

        console.log(folder)
      }
    }

    FileDialog {
      id: new_playlist_dialog
      title: "Save playlist"
      visible: false
      fileMode: FileDialog.SaveFile
      onAccepted: {
        console.log("save playlist")

        console.log(file)
      }
    }

    FileDialog {
      id: add_track_dialog
      title: "Add Track"
      fileMode: FileDialog.OpenFiles
      visible: false
      onAccepted: {
        PlayListManager.addTrack(files);

      }
    }

    Rectangle {
      id: upperBlock
      height: openBtn.height
      width: root.width
      color: transparentColor
      Row {
        anchors.right: parent.right
        spacing: 15
        ButtonStandart {
          id: openBtn
          mainText: "open playlist"
          backgroundColor: transparentColor
          enabled: !open_playlist_dialog.visible
          onClicked: {
            open_playlist_dialog.visible = true
          }
        }
        ButtonStandart {
          id: newBtn
          mainText: "new playlist"
          backgroundColor: transparentColor
          enabled: !new_playlist_dialog.visible
          onClicked: {
            new_playlist_dialog.visible = true
          }

        }
      }
    }
    Rectangle {
      id: listViewWrapper
      Layout.preferredHeight: root.height - upperBlock.height - bottom.height - spacer.height - 15
      Layout.preferredWidth: root.width
      color: transparentColor
      ListView {
        id: playList
        anchors.fill: parent
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        flickableDirection: Flickable.VerticalFlick

        model: PlayList
        spacing: 5
        delegate: Button {
          id: delegateItem
          width: listViewWrapper.width
          height: 25
          background: Rectangle {
            radius: 2
            gradient: Gradient {
              GradientStop { position: 0.0; color: (playList.currentIndex === model.index) ?
                                                     "#09d3ff" : "#043544" }
              GradientStop { position: 0.49; color: (playList.currentIndex === model.index) ?
                                                      "#09d3ff" : "#043544" }
              GradientStop { position: 0.5; color: (playList.currentIndex === model.index) ?
                                                     "#56b4d0" : Qt.alpha("#043544", 0.5) }
              GradientStop { position: 1.0; color: (playList.currentIndex === model.index) ?
                                                     "#56b4d0" : Qt.alpha("#043544", 0.5) }
            }
          }

          Text {
            id: trackNumberTxt
            anchors {
              left: parent.left
              leftMargin: 10
              verticalCenter: parent.verticalCenter
            }

            text: model.index + 1
            color: "white"
          }
          Text {
            id: trackNameTxt
            anchors {
              left: trackNumberTxt.right
              leftMargin: 5
              verticalCenter: parent.verticalCenter
            }
            text: {
              let fullPath = model.name;
              return fullPath.substring(fullPath.lastIndexOf("/") + 1);
            }
            color: "white"
          }
          Text {
            id: trackDuration
            anchors {
              right: parent.right
              rightMargin: 25
              verticalCenter: parent.verticalCenter
            }
            text: model.duration
            color: "white"
          }
          onClicked: {
            playList.currentIndex = model.index
            PlayListManager.currentTrack = model.name
          }
          onDoubleClicked: {
            playList.currentIndex = model.index
            PlayListManager.currentTrack = model.name
            AudioPlayer.play(true)
          }
        }
      }
    }
    Rectangle {
      id: bottom
      height: openBtn.height
      width: root.width
      color: transparentColor
      Row {
        anchors.left: parent.left
        spacing: 15
        ButtonStandart {
          id: addBtn
          mainText: "add track"
          backgroundColor: transparentColor
          enabled: !add_track_dialog.visible
          onClicked: {
            add_track_dialog.visible = true
          }
        }
        ButtonStandart {
          id: copyBtn
          mainText: "copy track"
          backgroundColor: transparentColor
          enabled: false
        }
        ButtonStandart {
          id: deleteBtn
          mainText: "delete track"
          backgroundColor: transparentColor
          enabled: false
        }
      }

    }
  }
}
