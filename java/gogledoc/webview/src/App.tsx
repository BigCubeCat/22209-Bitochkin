import {Route, Switch} from "wouter";
import LoginPage from "./pages/LoginPage.tsx";
import MainPage from "./pages/MainPage.tsx";

function App() {
  return (
    <>
      <Switch>
        <Route path="/login" component={LoginPage}/>
        <Route path="/" component={MainPage}/>
        <Route>404: No such page!</Route>
      </Switch>
    </>
  )
}

export default App
