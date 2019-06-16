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

app.get('/clubs', (req, res) => {
  let context = {};
  let clubsQuery = "SELECT club.id, club.name FROM club ORDER BY club.name";
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

app.get('/countries', (req, res) => {
  let context = {};
  let countriesQuery = "SELECT country.id, country.name AS country_name FROM country ORDER BY country.name";
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

app.delete('/countries/new', (req, res) => {
  let deleteEntry = req.body.id;
  let deleteCountryQuery = "DELETE FROM country WHERE id=?";
  mysql.pool.query(deleteCountryQuery, deleteEntry, (err, results, fields) => {
    if (err) res.json({error: err})
    res.json(results);
  })
});


app.get('/history', (req, res) => {
  let context = {};
  let leaguesClubsQuery = "SELECT league.id AS league_id, club.id AS club_id, league.name AS league_name, club.name AS club_name, club_league.year FROM league INNER JOIN club_league ON club_league.league_id = league.id INNER JOIN club ON club_league.club_id = club.id ORDER BY year, league.name, club.name";
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

app.delete('/history/new', (req, res) => {
  let deleteHistoryQuery = `DELETE FROM club_league WHERE club_id = ${req.body.club_id} AND league_id = ${req.body.league_id}`;
  mysql.pool.query(deleteHistoryQuery, (err, results, fields) => {
    if (err) {
      res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.get('/leagues', (req, res) => {
  let context = {};
  let leaguesQuery = "SELECT league.id, league.name AS name, country.name AS country_name FROM league INNER JOIN country ON league.country_id = country.id ORDER BY league.name";
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

app.get('/players', (req, res) => {
  let context = {};
  let playersQuery = "SELECT player.id, player.first_name, player.last_name, player.fee, player.market_value, country.name AS country_name, club.name AS club_name FROM player INNER JOIN country ON player.country_id = country.id LEFT JOIN club ON player.club_id = club.id ORDER BY player.last_name, player.first_name, club.name;"
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
      console.log(err);
			res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.delete('/players/new', (req, res) => {
  let deleteEntry = req.body.id;
  let deletePlayerQuery = "DELETE FROM player WHERE id=?";
  mysql.pool.query(deletePlayerQuery, deleteEntry, (err, results, fields) => {
    if (err) {
			res.write(JSON.stringify(err));
    } else {
      res.json(results);
    }
  });
});

app.put('/players/new', (req, res) => {
  let entryToUpdate = Object.assign({}, req.body);
  delete entryToUpdate["id"];

  mysql.pool.query(`SELECT id FROM country WHERE country.name = ?`, [`${req.body.country}`], (err, results, fields) => {
    if (err) {
      res.write(JSON.stringify(err));
    } else {
      delete entryToUpdate["country"];
      entryToUpdate.country_id = results[0].id;
      if (req.body.club != null) {
        mysql.pool.query(`SELECT id FROM club WHERE club.name = ?`, [`${req.body.club}`], (err, results, fields) => {
          if (err) {
            res.write(JSON.stringify(err));
          } else {
            delete entryToUpdate["club"];
            entryToUpdate.club_id = results[0].id;
            mysql.pool.query(`UPDATE player SET ? WHERE id = ${req.body.id}`, entryToUpdate, (err, results, fields) => { 
              if (err) {
                res.write(JSON.stringify(err));
              } else {
                res.json(results);
              }
            });
          }
        });
      } else {
        delete entryToUpdate["club"];
        entryToUpdate.club_id = null;
        mysql.pool.query(`UPDATE player SET ? WHERE id = ${req.body.id}`, entryToUpdate, (err, results, fields) => { 
          if (err) {
            res.write(JSON.stringify(err));
          } else {
            res.json(results);
          }
        });
      }
    }
  })
});

app.listen(port, () => console.log(`db-page listening on port ${port}!`));