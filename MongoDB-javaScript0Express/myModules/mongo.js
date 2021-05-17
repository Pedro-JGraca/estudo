class collection{
  constructor(db,collection) {
    this.dbplayers = db.collection(collection)
  }

  gerateID(id) {
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
    return ObjectId(id)
  }

  insertOneWithID(id,data){
    id = this.gerateID(id)
    if(id==false)
    {
      return false
    }
    //verificar se o ID é usado
    //verificar de data é json

    this.dbplayers.insertOne(
      {
        ...{'_id':id},...data}
    )
    
    return true
  }

  insertOneOffID(data){
    this.dbplayers.insertOne(data)
    return false
  }

  list(){
    this.dbplayers.find().toArray()
    .then(
      results => {
        console.log(results)
        return true
      })
    return false
  }

  searchByID(id)
  {
    let result
    id = this.gerateID(id)
    if(id==false)
    {
      return false
    }
    //verificar se o ID é usado
    
    let achou = false
    this.dbplayers.find().toArray()
    .then
    (
      results => 
      {
        for (let cont=0;cont<results.length;cont++)
        {
          if (results[cont]['_id'].toString() == id)
          {
            console.log('a')
            result = results[cont]
            achou = true
            return result
          }
        }
        if (achou == false)
        {
          return false
        }
      }
    )
    
  }
  searchByName(name){
    if(typeof(name)!=typeof(""))
    {
      return false
    }
    //verificar se o ID é usado
    console.log(this.dbplayers.findOne({"name":name}))
    return true
  }

}

module.exports = {collection}