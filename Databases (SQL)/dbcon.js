let mysql = require('mysql');
let pool = mysql.createPool({
  host  : 'classmysql.engr.oregonstate.edu',
  user  : 'cs340_student',
  password: 'xxxx',
  database: 'cs340_student'
});

module.exports.pool = pool;
