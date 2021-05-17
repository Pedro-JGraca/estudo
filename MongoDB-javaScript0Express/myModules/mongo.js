class collection{
  constructor(db,collection) {
    this.dbplayers = db.collection(collection)
  }

  insertOneWithID(id,data){
    const {ObjectId} = require('mongodb')

    if (typeof(id) != typeof(""))//se string do ID é falso
    {
      return false 
    }

    if (/^[A-F0-9]+$/i.test(id)==false) //se ID não é hexa
    {
      return false 
    }

    if (id.search('-')==0) //se o primeiro elemento é '-'
    {
      id = id.substring(1,id.length)
    }

    if (id.length < 24)
    {
      while(id.length!=24)
      {
        id = '0' + id 
      }
    }
    else if (id.length > 24)
    {
      id = id.substring(id.length-24,id.length) //caso tenha mais de 24, corta os maiores
    }

    //verificar se o ID é usado

    this.dbplayers.insertOne(
      {
        ...{'_id':ObjectId(id)},...data}
  )
    
    return true
  }
  insertOneOffID(register){
    
  }
  


  list(){
    dbplayers.find()
  }
}

module.exports = {collection}