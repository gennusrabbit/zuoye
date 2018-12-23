Page({

  /**
   * 页面的初始数据
   */
  data: {
    key: "0",

  },
  

  /**
   * 生命周期函数--监听页面加载
   */
  
  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  },
  change1: function (e) {
    //当有输入时激活发送按钮，无输入则禁用按钮
    if (e.detail.value != "") {
      this.setData({
        key: e.detail.value,
     
      })
    }

  },
  send1: function () {
    
    
    wx.showToast({
      title: "成功开门",
      duration: 1000
    })
    this.sendRequset(this.makeObj(this.data.key,""));
  },

  sendRequset: function (obj) {
    wx.request(obj);
  },
  makeObj: function (key, msg) {
    var obj = {
      url: "http://api.heclouds.com/devices/505394835/datapoints?type=3",

      header: {
        "Content-Type": "application/json",
        "api-key": "KZ=B7AgnL79KUHLnAa63N4j1MOc=",
      },1
      method: "post",
      data: {

        key
      },
      success: function (res) {
        if (msg != "") {
          wx.showToast({
            title: msg,
            duration: 2000
          })

        }
      }
    }
    return obj;
  }})