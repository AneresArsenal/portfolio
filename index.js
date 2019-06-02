const express = require('express')
const mysql = require('./dbcon.js');
const bodyParser = require('body-parser');
const app = express();
const port = 1992;

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(express.static('public'));

app.set('view engine', 'pug');

// In this example, we have the home page query the players table and send that information
// to the front end to display as a table
app.get('/', (req, res) => {
  res.render('index');
});

app.get('/players', (req, res) => {
  let context = {};
  let playersQuery = "SELECT player.id, player.first_name, player.last_name, player.fee, player.market_value, country.name AS country_name, club.name AS club_name FROM player INNER JOIN country ON player.country_id = country.id LEFT JOIN club ON player.club_id = club.id;"
  mysql.pool.query(playersQuery, (err, rows, fields) => {
    context.results = rows;
    let countriesQuery = "SELECT country.id, country.name FROM country";
    mysql.pool.query(countriesQuery, (err, rows, fields) => {
      context.countries = rows;
      let clubsQuery = "SELECT club.id, club.name FROM club";
      mysql.pool.query(clubsQuery, (err, rows, fields) => {
        context.clubs = rows;
        res.render('players', context)
      });
    });
  });
});

app.post('/players/new', (req, res) => {
  let newEntry = req.body;
  let insertPlayerQuery = "INSERT INTO player SET ?";
  mysql.pool.query(insertPlayerQuery, newEntry, (err, results, fields) => {
    if (err) {
			res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.get('/cashflows', (req, res) => {
  if (req.query.id) {
    let filteredCashflowQuery = `SELECT cashflow.id, club.name AS club_name, year, amount FROM club INNER JOIN cashflow ON club.id = cashflow.club_id WHERE cashflow.club_id = ${req.query.id} ORDER BY cashflow.year, cashflow.amount DESC`;

    if (req.query.id == "all") {
      filteredCashflowQuery = "SELECT cashflow.id, club.name AS club_name, year, amount FROM club INNER JOIN cashflow ON club.id = cashflow.club_id ORDER BY cashflow.year, cashflow.amount DESC";
    }
    
    mysql.pool.query(filteredCashflowQuery, (err, rows, fields) => {
      res.json(rows);
      return;
    });
  } else {
    let context = {};
    let clubsCashflowQuery = "SELECT cashflow.id, club.name AS club_name, year, amount FROM club INNER JOIN cashflow ON club.id = cashflow.club_id ORDER BY cashflow.year, cashflow.amount DESC";
    mysql.pool.query(clubsCashflowQuery, (err, rows, fields) => {
      context.results = rows;
      let clubsQuery = "SELECT club.id, club.name FROM club;"
      mysql.pool.query(clubsQuery, (err, rows, fields) => {
        context.clubs = rows;
        res.render('cashflows', context)
      });
    });
  }

});

app.post('/cashflows/new', (req, res) => {
  let newEntry = req.body;
  let insertCashflowQuery = "INSERT INTO cashflow SET?;";
	mysql.pool.query(insertCashflowQuery, newEntry, (err, results, fields) => {
		if (err) {
      res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.get('/countries', (req, res) => {
  let context = {};
  let countriesQuery = "SELECT country.id, country.name AS country_name FROM country";
  mysql.pool.query(countriesQuery, (err, rows, fields) => {
    context.results = rows;
    res.render('countries', context)
  });
});

app.post('/countries/new', (req, res) => {
  let newEntry = req.body.country;
  let insertCountryQuery = "INSERT INTO country SET name=?";
	mysql.pool.query(insertCountryQuery, newEntry, (err, results, fields) => {
		if (err) {
      
			res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
	});
});

app.get('/history', (req, res) => {
  let context = {};
  let leaguesClubsQuery = "SELECT league.id AS league_id, club.id AS club_id, league.name AS league_name, club.name AS club_name, club_league.year FROM league INNER JOIN club_league ON club_league.league_id = league.id INNER JOIN club ON club_league.club_id = club.id";
  mysql.pool.query(leaguesClubsQuery, (err, rows, fields) => {
    context.results = rows;
    let clubsQuery = "SELECT club.id, club.name FROM club";
    mysql.pool.query(clubsQuery, (err, rows, fields) => {
      context.clubs = rows;
      let leaguesQuery = "SELECT league.id, league.name FROM league";
      mysql.pool.query(leaguesQuery, (err, rows, fields) => {
        context.leagues = rows;
        res.render('league-clubs', context)
      });
    });
  });
});

app.post('/history/new', (req, res) => {
  let newEntry = req.body;
  let insertHistoryQuery = "INSERT INTO club_league SET ?";
  mysql.pool.query(insertHistoryQuery, newEntry, (err, results, fields) => {
    if (err) {
      res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.get('/leagues', (req, res) => {
  let context = {};
  let leaguesQuery = "SELECT league.id, league.name AS name, country.name AS country_name FROM league INNER JOIN country ON league.country_id = country.id";
  mysql.pool.query(leaguesQuery, (err, rows, fields) => {
    context.results = rows;
    let countriesQuery = "SELECT country.id, country.name FROM country";
    mysql.pool.query(countriesQuery, (err, rows, fields) => {
      context.countries = rows;
      res.render('leagues', context);
    });
  });
});

app.post('/leagues/new', (req, res) => {
  let newEntry = req.body;
  let insertLeaguesQuery = "INSERT INTO league SET ?";
  mysql.pool.query(insertLeaguesQuery, newEntry, (err, results, fields) => {
    if (err) {
      res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.get('/clubs', (req, res) => {
  let context = {};
  let clubsQuery = "SELECT club.id, club.name FROM club";
  mysql.pool.query(clubsQuery, (err, rows, fields) => {
    context.results = rows;
    res.render('clubs', context);
  });
});

app.post('/clubs/new', (req, res) => {
  let newEntry = req.body;
  let insertClubsQuery = "INSERT INTO club SET ?";
  mysql.pool.query(insertClubsQuery, newEntry, (err, results, fields) => {
    if (err) {
      res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

// We have to update this

// app.post('/', (req, res) => {
//   // We have to fit everything under this post request (no DELETE or PUT allowed apparently)
//   // So we have to parse the action from the POST request to use the right handler
//   if (req.body.action == "add") {
//     let newEntry = Object.assign({}, req.body);
//     delete newEntry["action"];

//     newEntry.date = moment(req.body.date, "MM-DD-YYYY").toDate();
//     mysql.pool.query("INSERT INTO workouts SET ?", newEntry, (err, results, fields) => {
//       if (err) {
//         res.json({error: err});
//       }
//       res.json(results);
//     });
//   } else if (req.body.action == "delete") {
//     mysql.pool.query(`DELETE FROM workouts WHERE id = ${req.body.id}`, (err, results, fields) => {
//       if (err) res.json({error: err})

//       res.json(results);
//     })
//   } else if (req.body.action == "edit") {
//     let entryToUpdate = Object.assign({}, req.body);

//     delete entryToUpdate["action"];
//     delete entryToUpdate["id"];

//     entryToUpdate.date = moment(req.body.date, "MM-DD-YYYY").toDate();
//     mysql.pool.query(`UPDATE workouts SET ? WHERE id = ${req.body.id}`, entryToUpdate, (err, results, fields) => {
//       if (err) {
//         res.json({error: err});
//       }
//       res.json(results);
//     });
//   }

// });

// We might want to alter this so that we can reset whatever table that we want

// app.get('/reset-table', (req, res, next) => {
//   let context = {};
//   mysql.pool.query("DROP TABLE IF EXISTS workouts", (err) => { //replace your connection pool with the your variable containing the connection pool
//     var createString = "CREATE TABLE workouts("+
//     "id INT PRIMARY KEY AUTO_INCREMENT,"+
//     "name VARCHAR(255) NOT NULL,"+
//     "reps INT,"+
//     "weight INT,"+
//     "date DATE,"+
//     "lbs BOOLEAN)";
//     mysql.pool.query(createString, (err) => {
//       context.message = "Table reset";
//       res.render('index', context);
//     });
//   });
// });

app.listen(port, () => console.log(`db-page listening on port ${port}!`));