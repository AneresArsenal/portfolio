const express = require('express')
const bodyParser = require('body-parser');
const app = express();
const port = 8893;

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(express.static('public'));

app.set('view engine', 'pug');

// In this example, we have the home page query the players table and send that information
// to the front end to display as a table
app.get('/mainPage', (req, res) => {
  res.render('mainPage');
});

app.get('/about', (req, res) => {
  res.render('about');
});

app.get('/data', (req, res) => {
  res.render('data');
});

app.get('/diary', (req, res) => {
  res.render('diary');
});

app.get('/projects', (req, res) => {
  res.render('projects');
});

app.get('/personal', (req, res) => {
  res.render('personal');
});

app.get('/myStory', (req, res) => {
  res.render('myStory');
});

app.listen(port, () => console.log(`db-page listening on port ${port}!`));