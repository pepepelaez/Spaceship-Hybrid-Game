import React, { Component } from "react";
import ReactDOM from "react-dom";

import "./styles.css";

//payers pages
var pages = {
  start: {
    content:
      "Welcome to the Koros Starship, identify yourself",
    image1: "",
    label1: "I am the Engineer",
    label2: "I am the Pilot",
    page1: "player1",
    page2: "player2"
  }

  class Page extends Component {
  render() {
    var pageData = pages[this.props.pageName];
    if (!pageData) {
      throw new Error("Eek! No page here!");
    }

    var goToPage = this.props.goToPage;
    //var useUserData = this.props.useUserData;

    function goToPage1() {
      goToPage(pageData.page1);
    }
    function goToPage2() {
      goToPage(pageData.page2);
    }

  return (
    <div className="App">
      <Page
        pageName={this.state.page}
        goToPage={this.goToPage}
        userData={this.state.userData}
        saveUserData={this.saveUserData}
        {button1}
        {button2}
        //useUserData={this.useUserData}
      />
    </div>
  );
  }
}



class ControlComponent extends React.Component {
  constructor(props) {
    super(props);

    // make a websocket connection to the server we loaded this page from.
    this.socket = new WebSocket(`ws://${window.location.host}/comm`);

    // when the socket closes, issue an alert.
    this.socket.addEventListener('close', () => {
      alert("Socket connection to server closed.");
    });

    // when there's a message from the server, use the handleMessage function
    // to handle it.
    this.socket.addEventListener('message', message => {
      this.handleMessage(message);
    })
  }

  handleMessage(message) {
    console.log("Message:", message.data);
    // do something with this data?
  }

  sendMessage(message) {
    // send the message to the server over the websocket.
    this.socket.send(message);
  }

  class App extends Component {
  constructor(props) {
    super(props);

    this.state = {
      page: "start",
      userData: {}
    };

    this.goToPage = this.goToPage.bind(this);

    goToPage(pageName) {
    this.setState({
      page: pageName
    });
  }

  saveUserData(key, value) {
    function updateState(state) {
      var newState = { userData: { ...state.userData, [key]: value } };
      return newState;
    }
    this.setState(updateState);
  }

  render() {
    // four buttons. see index.html for styling.
    return <div className="wrapper">
        <button onClick={() => this.sendMessage("P1a")}>P1: Go to Room A</button><br />
        <button onClick={() => this.sendMessage("P1b")}>P1: Go to Room B</button><br />
        <button onClick={() => this.sendMessage("P1c")}>P1: Go to Room C</button><br />
        <button onClick={() => this.sendMessage("P1d")}>P1: Go to Room D</button><br />
        <button onClick={() => this.sendMessage("P2a")}>P2: Go to Room A</button><br />
        <button onClick={() => this.sendMessage("P2b")}>P2: Go to Room B</button><br />
        <button onClick={() => this.sendMessage("P2c")}>P2: Go to Room C</button><br />
        <button onClick={() => this.sendMessage("P2d")}>P2: Go to Room D</button><br />
        <button onClick={() => this.sendMessage("A1a")}>Spawn Alien1 Room A</button><br />
        <button onClick={() => this.sendMessage("A1b")}>Spawn Alien1 Room B</button><br />
        <button onClick={() => this.sendMessage("A1c")}>Spawn Alien1 Room C</button><br />
        <button onClick={() => this.sendMessage("A1d")}>Spawn Alien1 Room D</button><br />
        <button onClick={() => this.sendMessage("A2a")}>Spawn Alien2 Room A</button><br />
        <button onClick={() => this.sendMessage("A2b")}>Spawn Alien2 Room B</button><br />
        <button onClick={() => this.sendMessage("A2c")}>Spawn Alien2 Room C</button><br />
        <button onClick={() => this.sendMessage("A2d")}>Spawn Alien2 Room D</button><br />
        <button onClick={() => this.sendMessage("KA1P1")}>P1: Kill Alien 1</button><br />
        <button onClick={() => this.sendMessage("KA2P1")}>P1: Kill Alien 2</button><br />
        <button onClick={() => this.sendMessage("KA1P2")}>P2: Kill ALien 1</button><br />
        <button onClick={() => this.sendMessage("KA2P2")}>P2: Kill Alien 2</button><br />
        <button onClick={() => this.sendMessage("SP1")}>P1: Set Room</button><br />
        <button onClick={() => this.sendMessage("SP2")}>P2: Set Room</button><br />


      </div>
  }
}

// render that control component, defined above, into the "root" element of index.html
ReactDOM.render(
  <ControlComponent />,
  document.getElementById('root')
);
