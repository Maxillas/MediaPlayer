import QtQuick
import QtQuick.Layouts
import "../Components"
import "../Resources"

Rectangle {
  id: root
  property color textColor: "#5caabe"
  property color backgroundColor: "#043544"
  property color transparentColor: Qt.alpha(backgroundColor, 0)

  function formatDuration(duration) {
    let hours  = Math.floor(duration / 3600000);
    let minutes = Math.floor((duration % 3600000) / 60000);
    let secs = Math.floor((duration % 60000) / 1000);

    return ("0" + hours).slice(-2) + ":" +
           ("0" + minutes).slice(-2) + ":" +
           ("0" + secs).slice(-2);
  }

  // height: root.height * 1/3
  // width: root.width
  // color: transparentColor

  ProgressBar {
    id: progressBar
    width: root.width
    anchors.top: root.top
    anchors.topMargin: 15
  }

  Text {
    id: progress_time
    anchors.left: parent.left
    anchors.top: progressBar.bottom
    anchors.topMargin: 10
    anchors.leftMargin: 5
    text: {
      if(!PlayListManager) {return "";}
      formatDuration(AudioPlayer.position)
    }
    font.pointSize: 12
    color: textColor
  }

  Text {
    id: full_time
    anchors.right: parent.right
    anchors.top: progressBar.bottom
    anchors.topMargin: 10
    anchors.rightMargin: 5
    text: {
      if(!PlayListManager) {return "";}
      formatDuration(AudioPlayer.duration)
    }
    font.family: "Arial"
    font.pointSize: 12
    color: textColor
  }

  Text {
    id: txt
    anchors.left: parent.left
    anchors.top: progress_time.bottom
    anchors.topMargin: 10
    anchors.leftMargin: 5
    text: {
      if(!PlayListManager) {return "";}
      qsTr("Playlist time ") + root.formatDuration(PlayListManager.playlistDuration)
    }

    font.family: "Arial"
    font.pointSize: 12
    color: textColor
  }

  // Rectangle {
  //   id: button_wrapper
  //   anchors.top: progressBar.bottom
  //   anchors.horizontalCenter: parent.horizontalCenter
  //   height: parent.height
  //   //width: parent.width / 2
  //   color: transparentColor

    ButtonRound {
      id: stopBtn
      height: parent.height / 3
      anchors {
        verticalCenter: playBtn.verticalCenter
        right: prevBtn.left
        rightMargin: 25
      }
      imageSource: "../Resources/stop.png"
      onClicked: {
        AudioPlayer.stop();
      }
    }
    ButtonRound {
      id: prevBtn
      height: parent.height / 3
      anchors {
        verticalCenter: playBtn.verticalCenter
        right: playBtn.left
        rightMargin: 25
      }
      imageSource: "../Resources/backward.png"

    }
    ButtonRound {
      id: playBtn
      height: parent.height
      anchors {
        horizontalCenter: parent.horizontalCenter
        top: progressBar.bottom
        topMargin: 5
      }
      imageSource: {
        if(!AudioPlayer) {return "";} //проверка на существование объекта с++
        !AudioPlayer.isPlaying ? "../Resources/play.png" : "../Resources/pause.png"
      }

      onClicked: {
        AudioPlayer.isPlaying ? AudioPlayer.pause() : AudioPlayer.play(false)
      }
    }
    ButtonRound {
      id: nextBtn
      height: parent.height / 3
      anchors {
        verticalCenter: playBtn.verticalCenter
        left: playBtn.right
        leftMargin: 25
      }
      imageSource: "../Resources/forward.png"
    }
    ButtonRound {
      id: repeatBtn
      height: parent.height / 3
      anchors {
        verticalCenter: playBtn.verticalCenter
        left: nextBtn.right
        leftMargin: 25
      }
      imageSource: "../Resources/repeat.png"
      onClicked: {
        AudioPlayer.repeat()
      }
    }


}
