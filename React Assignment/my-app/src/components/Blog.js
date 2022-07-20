
import { useState, useEffect } from "react"
import axios from 'axios';

const baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs?select=*'

const Blog = () => {
    const [blogs, setBlogs] = useState(null)
    const [loading, setLoading] = useState(true)

    useEffect(() => {
        axios.get(baseURL, {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey' : 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'  
            }
        }).then((response) => {
            setBlogs(response.data)
            setLoading(false)
            console.log('data', response)
        });
    }, [])

    return (
        <div className="container">
            {
                loading ? <h1>Loading...</h1> :
                    <>
                        {
                            blogs.map((blog, index) => {
                                return <div class="card" style={{width: 500 ,align:'center'}}>
                                <img class="card-img-top" src="https://images.unsplash.com/photo-1604085572504-a392ddf0d86a?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxzZWFyY2h8MXx8b3JhbmdlJTIwZmxvd2VyfGVufDB8fDB8fA%3D%3D&w=1000&q=80" alt="..." height={100} width={100}></img>
                                <div class="card-body">
                                  <h5 class="card-title">{blog.title}</h5>
                                  <p class="card-text">{blog.description}</p>
                                </div>
                              </div>
                                // return <div className="card" key={blog.id}>
                                //     <div className="box">
                                //         <div className="content">
                                //             <h2>{index + 1}</h2>
                                //             <h3>{blog.title}</h3>
                                //             <p>{blog.description}</p>
                                //             <a href="#">Read More</a>
                                //         </div>
                                //     </div>
                                // </div>
                            })
                        }
                    </>
            }

        </div>
    )
}

export default Blog;