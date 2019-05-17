class ControlComponent extends React.Component {
  constructor(props) {
    super(props);

    this.state = { player: 0 };
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

  render() {
    if (this.state.player === 0) {
      return (<div>
        <button onClick={() => this.setState({player: 1})}>I'm player 1!</button><br />
        <button onClick={() => this.setState({player: 2})}>I'm player 2!</button>
      </div>)
    } else {
      var ps = "";
      var name = "";
      if (this.state.player === 1) {
        ps = "P1";
        name = "Player 1";
      }
      if (this.state.player === 2) {
        ps = "P2";
        name = "Player 2";
      }
      return (
        <div className="wrapper">
        <p>{name}</p>
          <button onClick={() => this.sendMessage(ps+"a")}>Go to Room A</button><br />
          <button onClick={() => this.sendMessage(ps+"b")}>Go to Room B</button><br />
          <button onClick={() => this.sendMessage(ps+"c")}>Go to Room C</button><br />
          <button onClick={() => this.sendMessage(ps+"d")}>Go to Room D</button><br />
          <button onClick={() => this.sendMessage("KA1"+ps)}>Kill Alien 1</button><br />
          <button onClick={() => this.sendMessage("KA2"+ps)}>Kill Alien 2</button><br />
          <button onClick={() => this.sendMessage("S"+ps)}>Set Room</button><br />

          </div>
        );
       }
     }
   }




    //return <div className="wrapper">
        //<button onClick={() => this.sendMessage("P1a")}>P1: Go to Room A</button><br />
        //<button onClick={() => this.sendMessage("P1b")}>P1: Go to Room B</button><br />
        //<button onClick={() => this.sendMessage("P1c")}>P1: Go to Room C</button><br />
        //<button onClick={() => this.sendMessage("P1d")}>P1: Go to Room D</button><br />
        //<button onClick={() => this.sendMessage("P2a")}>P2: Go to Room A</button><br />
        //<button onClick={() => this.sendMessage("P2b")}>P2: Go to Room B</button><br />
        //<button onClick={() => this.sendMessage("P2c")}>P2: Go to Room C</button><br />
        //<button onClick={() => this.sendMessage("P2d")}>P2: Go to Room D</button><br />
        //<button onClick={() => this.sendMessage("A1a")}>Spawn Alien1 Room A</button><br />
        //<button onClick={() => this.sendMessage("A1b")}>Spawn Alien1 Room B</button><br />
        //<button onClick={() => this.sendMessage("A1c")}>Spawn Alien1 Room C</button><br />
      //  <button onClick={() => this.sendMessage("A1d")}>Spawn Alien1 Room D</button><br />
        //<button onClick={() => this.sendMessage("A2a")}>Spawn Alien2 Room A</button><br />
        //<button onClick={() => this.sendMessage("A2b")}>Spawn Alien2 Room B</button><br />
        //<button onClick={() => this.sendMessage("A2c")}>Spawn Alien2 Room C</button><br />
        //<button onClick={() => this.sendMessage("A2d")}>Spawn Alien2 Room D</button><br />
        //<button onClick={() => this.sendMessage("KA1P1")}>P1: Kill Alien 1</button><br />
        //<button onClick={() => this.sendMessage("KA2P1")}>P1: Kill Alien 2</button><br />
        //<button onClick={() => this.sendMessage("KA1P2")}>P2: Kill ALien 1</button><br />
        //<button onClick={() => this.sendMessage("KA2P2")}>P2: Kill Alien 2</button><br />
      //  <button onClick={() => this.sendMessage("SP1")}>P1: Set Room</button><br />
      //  <button onClick={() => this.sendMessage("SP2")}>P2: Set Room</button><br />

    //  </div>





// render that control component, defined above, into the "root" element of index.html
ReactDOM.render(
  <ControlComponent />,
  document.getElementById('root')
);
