function myFunction2() {
  document.getElementById("myDropdown2").classList.toggle("show2");
}

//Close the dropdown menu if the user clicks outside of it
$("#close2").on("click",function(){
  if (!event.target.matches('.dropbtn2')) {
    var dropdowns = document.getElementsByClassName("dropdown-content2");
    var i;
    for (i = 0; i < dropdowns.length; i++) {
      var openDropdown = dropdowns[i];
      if (openDropdown.classList.contains('show2')) {
        openDropdown.classList.remove('show2');
      }
    }
  }
});
  

