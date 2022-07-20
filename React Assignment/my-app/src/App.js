
import './App.css';
import Blog from './components/Blog';
import Addblog from'./components/Addblog';
import Nav from './components/Nav'
function App() {
  return (
    <div className="App">
      <Nav />
      <h1>"Blogs"</h1>
      <Blog></Blog>
      <br></br>
    </div>
  );
}

export default App;
