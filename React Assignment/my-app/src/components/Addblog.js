import React,{ useState } from "react"
import Button from 'react-bootstrap/Button';
import axios from "axios";
import { Link } from "react-router-dom";

const baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs?select=*'

const Addblog=()=>{

    const [data, setData]=useState({
        title:"",
        description:"",
        author:"",
        reading_time :""

    })

    const handle=(f)=>{ 
        const newData={...data}
        newData[f.target.id]=f.target.value
        setData(newData)
        console.log(newData)

    }

    function addnote(){
        console.log(data)

        axios.post(
            baseURL,
            data,
            {
                headers:{
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey' : 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'  
                }
            }
        ).then(console.log('#######'));
      
    }


    return(
        <div>
            <form>
                <input onChange={(f)=>handle(f)} id="title" value={data.title} placeholder="title" type="text"></input>
                <input onChange={(f)=>handle(f)} id="description" value={data.description} placeholder="description" type="text"></input>
                <input onChange={(f)=>handle(f)} id="author" value={data.author} placeholder="author" type="text"></input>
                <input onChange={(f)=>handle(f)} id="reading_time" value={data.reading_time} placeholder="reading_time" type="number"></input>
                <Button onClick={addnote}><Link to="/">Add Blog</Link> </Button>
            </form>
    
            

        </div>
        )

}

export default Addblog;
