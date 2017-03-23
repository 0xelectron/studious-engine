#! /usr/local/bin/python3
import cgi
import json
import athletemodel
import yate
import athletelist

athletes = athletemodel.get_from_store()
form_data = cgi.FieldStorage()
athlete_name = form_data['which_athlete'].value
athlete_data = json.dumps(athletes[athlete_name])
athlete_data.to_dict()
print(yate.start_response('application/json'))
print(athlete_data)
