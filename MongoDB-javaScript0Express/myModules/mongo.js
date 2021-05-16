class collection{
  constructor(db,collection) {
    this.dbplayers = db.collection(collection)
  }

  insertOne(register){
    this.dbplayers.insertOne(register)
  }


  list(){
    dbplayers.find()
  }
}

module.exports = {collection}