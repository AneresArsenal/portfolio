let inEditMode = false;
const BACKGROUND_COLOUR = "#83c6f3";
const COMPLEMENTARY_COLOUR = "#f3aa83";

document.addEventListener("click", (e) => {
	if (e.target && e.target.id == "submit-cashflow-button") {
		addNewCashflow(e);
		document.getElementById('year').value='';
		document.getElementById('amount').value='';
	} else if (e.target && e.target.id == "search-cashflows-button") {
		showFilteredCashflows(e)
	} else if (e.target && e.target.id == "show-all-cashflows-button") {
		showAllCashflows(e)
	} else if (e.target && e.target.id == "submit-club-button") {
		addNewClub(e);
		document.getElementById('club-name').value='';
	} else if (e.target && e.target.id == "submit-country-button") {
		addNewCountry(e);
		document.getElementById('country').value='';
	} else if (e.target && e.target.id == "delete-country-button") {
    deleteCountry(e);
  } else if (e.target && e.target.id == "submit-league-button") {
		addNewLeague(e);
		document.getElementById('league-name').value='';
	} else if (e.target && e.target.id == "submit-league-club-button") {
		addNewLeagueClub(e);
		document.getElementById('year').value='';
  } else if (e.target && e.target.id == "delete-league-club-button") {
    deleteLeagueClub(e);
  } else if (e.target && e.target.id == "submit-player-button") {
		addNewPlayer(e);
		document.getElementById('first-name').value='';
		document.getElementById('last-name').value='';
		document.getElementById('fee').value='';
		document.getElementById('market-value').value='';
	} else if (e.target && e.target.id == "delete-player-button") {
		deletePlayer(e);
  } else if (e.target && e.target.className == "editable" && !inEditMode) {
		showDropdownOptions(e);
	} else if (e.target && (e.target.id.includes("edit-player-button") || e.target.id.includes("save-player-button"))) {
		editPlayer(e);
	} else if (e.target && e.target.id.includes("finish-edit-button")) {
		finishEditPlayer(e);
	}
});

let previousData = {club: null, country: null};

function showDropdownOptions(e) {
	e.preventDefault();

	inEditMode = true;

	let id = e.target.parentNode.id;

	let clubColumnToReplace = document.getElementById(`${id}-club-name`)
	let countryColumnToReplace = document.getElementById(`${id}-country-name`)

	// Save this data for later
	previousData.club = clubColumnToReplace.textContent;
	previousData.country = countryColumnToReplace.textContent;

	let countrySelects = document.getElementById("countries-options").cloneNode(true);
	countrySelects.id = `${id}-countries-options`;
	countryColumnToReplace.textContent = "";
	countryColumnToReplace.appendChild(countrySelects);

	let clubSelects = document.getElementById("clubs-options").cloneNode(true);
	clubSelects.id = `${id}-clubs-options`;
	clubColumnToReplace.textContent = "";
	clubColumnToReplace.appendChild(clubSelects);

	let savePlayerButton = document.getElementById(`${id}-save-player-button`);

	// If we edited before and want to edit again, then we need to target the button at its
	// correct state
	if (savePlayerButton) {
		// This is editing a second time before saving
		document.getElementById(`${id}-save-player-button`).textContent = "Finish edit";
		document.getElementById(`${id}-save-player-button`).id = `${id}-finish-edit-button`;	
	} else {
		// This is first-time edit
		document.getElementById(`${id}-edit-player-button`).textContent = "Finish edit";
		document.getElementById(`${id}-edit-player-button`).id = `${id}-finish-edit-button`;	
	}
	
}

function finishEditPlayer(e) {
	e.preventDefault();

	let isTouched = false;
	let id = e.target.parentNode.parentNode.id;

	let selectedClubOption = document.getElementById(`${id}-clubs-options`);
	let selectedCountryOption = document.getElementById(`${id}-countries-options`);

	let clubCell = document.getElementById(`${id}-club-name`)
	let countryCell = document.getElementById(`${id}-country-name`)
	
	clubCell.textContent = selectedClubOption[selectedClubOption.selectedIndex].textContent
	countryCell.textContent = selectedCountryOption[selectedCountryOption.selectedIndex].textContent;

	if (clubCell.textContent != previousData.club) {
		clubCell.style.backgroundColor = COMPLEMENTARY_COLOUR;
		isTouched = true;
	}

	if (countryCell.textContent != previousData.country) {
		countryCell.style.backgroundColor = COMPLEMENTARY_COLOUR;
		isTouched = true;
	}

	
	document.getElementById(`${id}-finish-edit-button`).textContent = "Edit player";
	document.getElementById(`${id}-finish-edit-button`).id = `${id}-edit-player-button`;	

	previousData.club = null;
	previousData.country = null;

	inEditMode = false;
}

function addNewCashflow(e) {
	e.preventDefault();
	let year = document.getElementById("year").value;
	let amount = document.getElementById("amount").value;

	if (year < 1900) {
		let message = "Error: Please enter a valid year from 1900 onwards"; 
		showError(message);
		return;
	}

	if (year > 2019) {
		let message = "Error: Invalid year entered. Input year is over 2019"; 
		showError(message);
		return;
	}

	let selectedClubOption = document.getElementById("clubs-options");
	let clubId = selectedClubOption[selectedClubOption.selectedIndex].id;

	let payload = {
		club_id: clubId,
		year: year,
		amount: amount
	};

	fetch('http://localhost:1992/cashflows/new', {
		method: "POST",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
	})
	.then(res => res.json())
	.then((myJson) => {
		if (myJson.error) {
			console.error(myJson.error);
			return;
		}
		
		// Making a copy instead of mutating the original payload
		let newPayload = Object.assign({}, payload);

		// These actually hold the values instead of the ids for display
		newPayload.club_id = selectedClubOption[selectedClubOption.selectedIndex].text;

		let appendContext = {
			id: myJson.insertId,
			payload: newPayload,
		};

		let tableBody = document.getElementById("db-table-body");
		if (tableBody.children.length == 0) {
			fetch("http://localhost:1992/cashflows?id=all", { 
				method: "GET"
			})
			.then((res) => res.json())
			.then((myJson) => {
				if (myJson.error) {
					console.error(myJson.error);
					return;
				}

				let ctx = {
					newData: myJson,
					editMessage: "Edit this cashflow",
					deleteMessage: "Delete this cashflow"
				};

				replaceTableData(ctx)
				});
		} else {
			addNewRow(appendContext);
		}

		showSuccess();
	});
}

function showFilteredCashflows(e) {
	e.preventDefault();

	let selectedClubOption = document.getElementById("filtered-clubs");
	let clubId = selectedClubOption[selectedClubOption.selectedIndex].id;

	let filterURI = `http://localhost:1992/cashflows?id=${clubId}`;

	fetch(filterURI, {
		method: "GET"
	})
	.then((res) => res.json())
	.then((myJson) => {
		if (myJson.error) {
			console.error(myJson.error);
			return;
    }
    
    let ctx = {
      newData: myJson,
      editMessage: "Edit this cashflow",
			deleteMessage: "Delete this cashflow",
			entity: "cashflow"
    };

		replaceTableData(ctx)
	})
}

function showAllCashflows(e) {
  e. preventDefault();

  fetch("http://localhost:1992/cashflows?id=all", { 
    method: "GET"
  })
  .then((res) => res.json())
  .then((myJson) => {
    if (myJson.error) {
      console.error(myJson.error);
      return;
    }

    let ctx = {
      newData: myJson,
      editMessage: "Edit this cashflow",
      deleteMessage: "Delete this cashflow"
    };

		replaceTableData(ctx)
  })
}

function addNewClub(e) {
	e.preventDefault();

	let name = document.getElementById("club-name").value;
	let payload = {
		name
	};

	fetch('http://localhost:1992/clubs/new', {
		method: "POST",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
	})
	.then((res => res.json()))
	.then((myJson) => {
		if (myJson.error) {
			console.error(myJson.error);
			return;
		}

		let appendContext = {
			id: myJson.insertId,
			payload,
		};

		addNewRow(appendContext);
	});
}

function addNewCountry(e) {
	e.preventDefault();
	let country = document.getElementById("country").value;
	let payload = {
		country
	};

	fetch('http://localhost:1992/countries/new', {
		method: "POST",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
	})
	.then(res => res.json())
	.then((myJson) => {
		if (myJson.error) {
			let errorMsg = `Error inserting into database: ${myJson.error.sqlMessage}`;
			showError(errorMsg);
			return;
		}

		let appendContext = {
			id: myJson.insertId,
			payload,
			deleteMessage: "Delete this country",
			entity: "country"
		}
		addNewRow(appendContext);
	})
}

function deleteCountry(e) {
	e.preventDefault();
    // This gives us the ID of the row to delete, stored in the <tr>'s id
	let id = e.target.parentNode.parentNode.id;
  let payload = {
    id,
  };

	fetch('http://localhost:1992/countries/new', {
		method: "DELETE",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
  })
  .then(res => res.json())
  .then((myJson) => {
    if (myJson.error) {
      let errorMsg = `Error deleting from database: ${myJson.error.sqlMessage}`;
      showError(errorMsg);
    } else {
      removeRow(id);
      showSuccess();
    }
  });
}

function addNewLeague(e) {
	e.preventDefault();

	let leagueName = document.getElementById("league-name").value;
	let selectedCountryOption = document.getElementById("countries-options");
	let selectedCountryId = selectedCountryOption[selectedCountryOption.selectedIndex].id;

	if (leagueName.length == 0) {
		let message = "Error: Please enter a league name"; 
		showError(message);
		return;
	}

	let payload = {
		name: leagueName,
		country_id: selectedCountryId
	}

	fetch('http://localhost:1992/leagues/new', {
		method: "POST",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
	})
	.then(res => res.json())
	.then((myJson) => {
		if (myJson.error) {
			console.error(myJson.error);
			return;
		}

		// Making a copy instead of mutating the original payload
		let newPayload = Object.assign({}, payload);

		// These actually hold the values instead of the ids for display
		newPayload.country_id = selectedCountryOption[selectedCountryOption.selectedIndex].text;

		let appendContext = {
			id: myJson.insertId,
			payload: newPayload,
		};

		addNewRow(appendContext);
	});
}

function addNewLeagueClub(e) {
  e.preventDefault();

  let selectedClubOption = document.getElementById("clubs-options");
  let clubId = selectedClubOption[selectedClubOption.selectedIndex].id;
  
  let selectedLeagueOption = document.getElementById("leagues-options");
  let leagueId = selectedLeagueOption[selectedLeagueOption.selectedIndex].id;

	let year = document.getElementById("year").value;
	
	if (year < 1900) {
		let message = "Error: Please enter a valid year from 1900 onwards"; 
		showError(message);
		return;
	}

	if (year > 2019) {
		let message = "Error: Invalid year entered. Input year is over 2019"; 
		showError(message);
		return;
	}
  
  let payload = {
    league_id: leagueId,
    club_id: clubId,
    year
  };

  fetch('http://localhost:1992/history/new', {
    method: "POST",
    body: JSON.stringify(payload),
    headers: {
      "Content-Type": "application/json"
    }
  })
  .then((res => res.json()))
  .then((myJson) => {
    if (myJson.error) {
      console.error(myJson.error);
      return;
    }

    // Making a copy instead of mutating the original payload
    let newPayload = Object.assign({}, payload);
    
    
    // These actually hold the values instead of the ids for display
    newPayload.club_id = selectedClubOption[selectedClubOption.selectedIndex].text;
    newPayload.league_id = selectedLeagueOption[selectedLeagueOption.selectedIndex].text;
    
    let appendContext = {
      id: myJson.insertId,
			payload: newPayload,
			deleteMessage: "Delete this record",
			entity: "league-club"
    }

    addNewRow(appendContext);
  });

  
}

function deleteLeagueClub(e) {
	e.preventDefault();
    // This gives us the ID of the row to delete, stored in the <tr>'s id
	let id = e.target.parentNode.parentNode.id;
	let res = id.split("-");
	let leagueId = res[0];
	let clubId = res[1];
  let payload = {
    league_id: leagueId,
    club_id: clubId,
  };

	fetch('http://localhost:1992/history/new', {
		method: "DELETE",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
  })
  .then(res => res.json())
  .then((myJson) => {
    if (myJson.error) {
      let errorMsg = `Error deleting from database: ${myJson.error.sqlMessage}`;
      showError(errorMsg);
    } else {
      removeRow(id);
      showSuccess();
    }
  });
}


function addNewPlayer(e) {
	e.preventDefault();
	let firstName = document.getElementById("first-name").value;
	let lastName = document.getElementById("last-name").value;
	let fee = document.getElementById("fee").value;
	let marketValue = document.getElementById("market-value").value;

	if (fee < 0) {
		let message = "Error: Fee must be greater than zero"; 
		showError(message);
		return;
	}

	if (marketValue < 0) {
		let message = "Error: Market Value must be greater than zero"; 
		showError(message);
		return;
	}

	let selectedClubOption = document.getElementById("clubs-options");
  let clubId = selectedClubOption[selectedClubOption.selectedIndex].id;
  
  if (clubId == "unsigned") {
    clubId = null;
  }

	let selectedCountryOption = document.getElementById("countries-options");
	let countryId = selectedCountryOption[selectedCountryOption.selectedIndex].id;

	let payload = {
		first_name: firstName,
    last_name: lastName,
    club_id: clubId,
		country_id: countryId,
		fee,
		market_value: marketValue
  };

	fetch('http://localhost:1992/players/new', {
		method: "POST",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
	})
	.then(res => res.json())
	.then((myJson) => {
		if (myJson.error) {
			console.error(myJson.error);
			return;
		}
		
		// Making a copy instead of mutating the original payload
		let newPayload = Object.assign({}, payload);

		// These actually hold the values instead of the ids for display
		newPayload.club_id = selectedClubOption[selectedClubOption.selectedIndex].text;
		newPayload.country_id = selectedCountryOption[selectedCountryOption.selectedIndex].text;

		let appendContext = {
			id: myJson.insertId,
			payload: newPayload,
			editMessage: "Edit this player",
			deleteMessage: "Delete this player",
			entity: "player"
		}
		addNewRow(appendContext);
	})
}

function deletePlayer(e) {
	e.preventDefault();
		// This gives us the ID of the row to delete, stored in the <tr>'s id
	let tableRow = e.target.parentNode.parentNode;
	let id = tableRow.id;
	let payload = {
		id,
	};

	fetch('http://localhost:1992/players/new', {
		method: "DELETE",
		body: JSON.stringify(payload),
		headers: {
			"Content-Type": "application/json"
		}
  })
  .then(res => res.json())
  .then((myJson) => {
    if (myJson.error) {
      let errorMsg = `Error deleting from database: ${myJson.error.sqlMessage}`;
      showError(errorMsg);
    } else {
      tableRow.remove();
			showSuccess();
    }
  });
}

function editPlayer(e) {
	e.preventDefault();

	let id = e.target.parentNode.parentNode.id;

	let firstName = document.getElementById(`${id}-first-name`).textContent;
	let lastName = document.getElementById(`${id}-last-name`).textContent;
	let fee = document.getElementById(`${id}-fee`).textContent;
	let marketValue = document.getElementById(`${id}-market-value`).textContent;

	if (fee < 0) {
		let message = "Error: Fee must be greater than zero"; 
		showError(message);
		return;
	}

	if (marketValue < 0) {
		let message = "Error: Market Value must be greater than zero"; 
		showError(message);
		return;
	}
	
	let countryCell = document.getElementById(`${id}-country-name`);
	// Set this back in case it was edited
	countryCell.style.backgroundColor = BACKGROUND_COLOUR
	let country = countryCell.textContent;

	let clubCell = document.getElementById(`${id}-club-name`)
	// Set this back in case it was edited
	clubCell.style.backgroundColor = BACKGROUND_COLOUR
	let club = clubCell.textContent;	

	if (club == "Free Agent (null)") {
		club = null;
	}

	let payload = {
		id,
		first_name: firstName,
		last_name: lastName,
		club,
		country,
		fee,
		market_value: marketValue,
	};

	fetch('http://localhost:1992/players/new', {
      method: "PUT",
      body: JSON.stringify(payload),
      headers: {
        "Content-Type": "application/json"
      }
    })
    .then(res => res.json())
    .then((myJson) => {
      if (myJson.error) {
        let errorMsg = `Error inserting into database: ${myJson.error.sqlMessage}`
        showError(errorMsg);
      } else {
        showSuccess();
      }
    });
}

function replaceTableData(context) {
  let oldTable = document.getElementById("db-table-body");
  if (context.newData.length == 0) {
		let noResultsMsg = createNoResultsMsg();
		let emptyTable = document.createElement("tbody");
		emptyTable.id = "db-table-body";
		oldTable.parentNode.replaceChild(emptyTable, oldTable);
		document.getElementById("result-message").innerHTML = '';
		document.getElementById("result-message").appendChild(noResultsMsg);
  } else {
    let newTable = populateTable(context);
    oldTable.parentNode.replaceChild(newTable, oldTable);
  }
}

function populateTable(context) {
  
  let newTableBody = document.createElement("tbody");
  newTableBody.id = "db-table-body";
	context.newData.forEach((entry) => {
		let tableRow = document.createElement("tr");
		tableRow.id = entry.id;
		Object.keys(entry).forEach((key) => {
      if (key != "id") {
        let tableData = document.createElement("td");
        tableData.textContent = entry[key];
        tableData.id = entry.id;
        tableRow.appendChild(tableData);
      }
    });

    newTableBody.appendChild(tableRow);
  });
  
  return newTableBody;
}

function createNoResultsMsg() {
  let noResults = document.createElement("div");
  noResults.textContent = "No results found";

  return noResults;
}

function addNewRow(context) {
	let tableBody = document.getElementById("db-table-body");
	let tableContentsRow = document.createElement("tr");
	tableContentsRow.id = context.id;
	tableBody.appendChild(tableContentsRow);
	Object.keys(context.payload).forEach((key) => {
		let tableRowData = document.createElement("td");
		tableRowData.textContent = context.payload[key];
		tableRowData.id = `${context.id}-${key}`
		tableRowData.setAttribute("contenteditable", "true");
		tableContentsRow.appendChild(tableRowData);
	});
	
	if (context.deleteMessage) {
		let deleteTableData = document.createElement("td");
		let deleteButton = document.createElement("button");
		deleteButton.setAttribute("type", "submit");
		deleteButton.id = `delete-${context.entity}-button`;
		deleteButton.textContent = context.deleteMessage;
		deleteTableData.appendChild(deleteButton);

		tableContentsRow.appendChild(deleteTableData);
	}

	if (context.editMessage){
		let editTableData = document.createElement("td");
		let editButton = document.createElement("button")
		editButton.setAttribute("type", "submit");
		editButton.id = "edit-button";
		editButton.textContent = context.editMessage;
		editTableData.appendChild(editButton);

		tableContentsRow.appendChild(editTableData);
	}
}

  function removeRow(id) {
    document.getElementById(id).remove();
  }

  function showError(message) {
		document.getElementById("result-message").style.color = "Red";
    document.getElementById("result-message").textContent = message;
  }

  function showSuccess() {
    document.getElementById("result-message").innerHTML = "Operation successful"
  }