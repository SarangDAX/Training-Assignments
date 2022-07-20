import { Link } from 'react-router-dom';

const Nav=()=>{
    return(

<nav class="navbar navbar-expand-lg navbar-light bg-primary">
  <a class="navbar-brand" href="#">Blogs</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>

  <div class="collapse navbar-collapse" id="navbarSupportedContent">
    <ul class="navbar-nav mr-auto">
      <li class="nav-item active">
        <Link className="nav-link" to ="/">BLOG LIST</Link>
      </li>
      <li class="nav-item">
        <Link className="nav-link" to ="/addblog">ADD BLOG</Link>
      </li>

    </ul>
  </div>
</nav>
    )
}

export default Nav;