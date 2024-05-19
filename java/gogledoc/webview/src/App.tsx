import './App.css'
import {Route, Switch} from "wouter";
import LoginPage from "./pages/LoginPage.tsx";

function App() {

  return (
    <>
      <Switch>
        <Route path="/login" component={LoginPage} />

        <Route path="/users/:name">
          {(params) => <>Hello, {params.name}!</>}
        </Route>

        {/* Default route in a switch */}
        <Route>404: No such page!</Route>
      </Switch>
    </>
  )
}

export default App
