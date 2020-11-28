const express = require('express')
const app = express()
const db_config = require(__dirname+'/config/database.js')
const conn = db_config.init()
const bodyParser = require('body-parser')
var session=require('express-session')
var mySqlStore= require('express-mysql-session')(session)
let router = express.Router();

var options = {
    host : 'localhost',
    port:3306,
    user:'root',
    password:'',
    database:'moodle'
}

var sessionStore = new mySqlStore(options)

app.use(session({
    secret : "kim",
    resave:false,
    saveUninitialized : true,
    store : sessionStore
}))



db_config.connect(conn);

app.set('views', __dirname+'/views')
app.set('view engine', 'ejs')

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({extended:false}))

app.get('/', function(req,res){
    //const body = req.body
    res.send("root")
})


let comment="comment 입력하세요"

app.get('/team', function(req,res){
    let sql = `select mdl_groups.name,groupid, firstname, lastname
               from mdl_groups_members, mdl_user,mdl_groups
               where mdl_groups_members.userid = mdl_user.id and 
                     mdl_groups_members.groupid=1 and 
                     mdl_groups_members.groupid = mdl_groups.id;
    `

    const names = []    
    //const lastNames = []
    conn.query(sql, function(err, rows, fields){
        if(err) console.log('query is not excuted. select fail...\n'+err)
        else {
            rows.forEach((element)=>{
                names.push(element.firstname+element.lastname)
            })
            console.log(rows[0].name)
  
            req.session.isLogined = true
            req.session.save(function(){
                res.render('team.ejs', {memberName:names,groupName:rows[0].name,comment:comment})
            })
            
        }
    })
  

})


app.post('/store', function(req, res){
    const body = req.body
    comment = body.memo
})

app.listen(3200, ()=>console.log('Sever is running on port 3200...'))