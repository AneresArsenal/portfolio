const express = require('express')
const bodyParser = require('body-parser');
const app = express();
const port = 8898;

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(express.static('public'));

app.set('view engine', 'pug');

// In this example, we have the home page query the players table and send that information
// to the front end to display as a table
app.get('/', (req, res) => {
  res.render('mainpage');
});

app.listen(port, () => console.log(`db-page listening on port ${port}!`));