<%@ Page Title="" Language="C#" MasterPageFile="~/BudgetManage.Master" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="BudgetManage.WebForm1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style type="text/css">
    #TextArea1 {
        height: 237px;
        width: 358px;
    }
</style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <p>
        &nbsp;Some random text which means nothing.</p>
<p>
    <textarea id="TextArea1" name="S1"></textarea></p>
<p>
    <asp:Button ID="Button1" runat="server" Text="Button" Width="128px" />
</p>
</asp:Content>
